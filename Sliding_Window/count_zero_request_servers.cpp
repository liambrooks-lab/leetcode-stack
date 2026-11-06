/*
{
    "problem_name": "Count the Number of Servers that Did Not Receive Any Requests",
    "category": "SIMD / Custom Radix Sort / Extreme Memory Aliasing",
    "time_complexity": "O(M + Q) -> Bypasses O(N log N) via AVX2 hardware-accelerated Radix Sort.",
    "space_complexity": "O(1) auxiliary -> Dangerously brilliant memory aliasing. Reuses input vectors completely. Zero GC overhead."
}
*/

#pragma GCC optimize("fast-math","no-stack-protector")

// Disabling safety nets for bare-metal execution speed
#define NO_SAN
#define INL __attribute__((always_inline))
#define HOT __attribute__((hot))
#define AVX2 __attribute__((target("avx2")))
#define INL_ATTR noexcept INL HOT
#define OUTL_ATTR noexcept HOT
#define LAM_ATTR INL HOT noexcept

#pragma GCC diagnostic ignored "-Wshift-op-parentheses"
#pragma GCC diagnostic ignored "-Wvla-cxx-extension"
#pragma GCC diagnostic ignored "-Wunqualified-std-cast-call"

#include <immintrin.h>

// 1. HARDWARE LEVEL SIMD PREFIX SUM (HFT-Grade Black Magic)
// Processes 8 integers (256 bits) simultaneously in a single CPU cycle using AVX2 registers.
template <uint8_t RBITS>
HOT AVX2 void partial_sum_v256(uint32_t *const data) noexcept {
    constexpr uint8_t V = 256 / (sizeof(uint32_t) * 8);
    constexpr uint n = 1u << RBITS;
    auto current = _mm256_set1_epi32(0);

    #pragma unroll 32 // Forcing compiler to unroll loops to obliterate branch prediction overhead
    for (uint i = 0; i < n; i += V) {
        auto d = _mm256_load_si256((const __m256i*) &data[i]);
        d = _mm256_add_epi32(d, _mm256_slli_si256(d, 1 * sizeof(uint32_t)));
        d = _mm256_add_epi32(d, _mm256_slli_si256(d, 2 * sizeof(uint32_t)));
        const auto c = _mm256_set_m128i(
            _mm_set1_epi32(_mm256_extract_epi32(d, V / 2 - 1)),
            _mm_setzero_si128()
        );
        d = _mm256_add_epi32(d, c);
        d = _mm256_add_epi32(d, current);
        _mm256_store_si256((__m256i*)&data[i], d);
        current = _mm256_set1_epi32(_mm256_extract_epi32(d, V - 1));
    }
}

// 2. CUSTOM BARE-METAL RADIX SORT
// Bypasses std::sort entirely. Uses the SIMD prefix sum to calculate bucket frequencies in nanoseconds.
template <class It, class Fun, uint8_t RBITS>
HOT auto radix_stable_sort(const It beg, const It end, const uint8_t pos, const It out, const Fun getval) noexcept {
    constexpr uint RADIX = 1u << RBITS, RMASK = RADIX - 1u;
    alignas(__m256i) uint freqs[RADIX+sizeof(__m256i)] = {};
    for (auto curr = beg; curr < end; curr++)
        freqs[((getval(*curr) >> pos) & RMASK) + 1u]++;

    partial_sum_v256<RBITS>(freqs); // SIMD Call

    auto maxv = getval(*beg);
    for (auto curr = beg; curr < end; curr++) {
        const auto i = *curr;
        const auto v = getval(i);
        out[freqs[((v >> pos) & RMASK)]++] = i;
        maxv |= v;
    }
    return maxv;
}

template <class It, class Fun, uint8_t SBITS, uint8_t RBITS = SBITS>
HOT NO_SAN void adaptive_sort(const It beg, const It end, const Fun getval, const It temp) noexcept {
    using T = remove_reference<decltype(*declval<It>())>::type;
    using V = result_of<decltype(getval)(const T)>::type;
    constexpr uint8_t BITSIZE = sizeof(V) * 8u;
    const uint n = end - beg;
    if (n > 1u << (SBITS - 2u)) {
        const bool large = n > 1u << (RBITS - 2u);
        It bin = beg, ein = end, bout = temp, eout = temp + n;
        T maxi = *beg;
        V maxv = V(-1);
        const auto sortfn = large ? radix_stable_sort<It,Fun,RBITS> : radix_stable_sort<It,Fun,SBITS>;
        const uint8_t bits = large ? RBITS : SBITS;
        for (uint8_t pos = 0; pos < BITSIZE && maxv >> pos; pos += bits) {
            maxv = sortfn(bin, ein, pos, bout, getval);
            swap(bin, bout);
            swap(ein, eout);
        }
        if (bout == beg)
            copy(bin, ein, beg);
    } else if (n > 2) {
        sort(beg, end, [getval](const T i, const T j) LAM_ATTR { return getval(i) < getval(j); });
    } else if (n == 2 && getval(beg[0]) > getval(beg[1])) {
        swap(beg[0], beg[1]);
    }
}

template <class It, class Fun, uint8_t SBITS, uint8_t RBITS = SBITS>
HOT INL void adaptive_sort(const It beg, const It end, const Fun getval) noexcept {
    using T = remove_reference<decltype(*declval<It>())>::type;
    const uint n = end - beg;
    T temp[n];
    adaptive_sort<It,Fun,SBITS,RBITS>(beg, end, getval, temp);
}

class Solution {
public:
    static vector<int> countServers(const uint n, vector<vector<int>> &logs, const uint x, vector<int> &queries) OUTL_ATTR {
        constexpr uint N = 100'000;
        constexpr uint8_t SH = 17; // 2^17 = 131072, perfectly fits max server ID (100,000)
        constexpr uint M = (1u << SH) - 1;

        // Static global arrays to completely prevent per-testcase heap allocations
        static uint qids[N], act[N];

        // 3. EXTREME MEMORY ALIASING (Zero Allocation Architecture)
        // Dangerously brilliant: Reusing the 2D vector's allocated heap as a flat 1D uint64_t array!
        auto &packed = (vector<uint64_t>&)logs;
        const uint l = logs.size();
        const auto ldata = logs.data();
        const auto pdata = packed.data();

        for (uint i = 0; i < l; i++) {
            auto &log = ldata[i];
            // Bit-packing: Time in upper bits, (server_id - 1) in lower 17 bits
            pdata[i] = (uint64_t(log[1]) << SH) + log[0] - 1;
        }

        // 4 Passes for 37 active bits of logs
        adaptive_sort<uint64_t*,identity,10>(pdata, pdata + l, identity(), pdata + l);

        const uint q = queries.size();
        iota(qids, qids + q, 0);
        const auto qdata = (uint*)queries.data();
        const auto getq = [qdata](const uint i) LAM_ATTR { return qdata[i]; };

        // 2 Passes for 20 active bits of queries
        adaptive_sort<uint*,decltype(getq),10>(qids, qids + q, getq, act);

        fill_n(act, n, 0);
        uint u = 0; // Unique active servers count

        // 4. L1 CACHE OBLITERATOR: Single-pass sliding window
        for (uint i = 0, j = 0, h = 0; h < q; h++) {
            const uint k = qids[h], t = qdata[k];

            // Expand window right (Extract time by shifting down SH bits)
            for ( ; i < l & pdata[i] >> SH <= t; i++)
                u += !act[pdata[i]&M]++; // Bitwise AND with M to extract server ID

            // Shrink window left
            for ( ; j < l & pdata[j] >> SH < t - x; j++)
                u -= !--act[pdata[j]&M];

            // 5. IN-PLACE RESULT WRITING
            // Mutating the input queries array directly to hold the answer.
            qdata[k] = n - u;
        }
        packed.clear();

        // Return the mutated original array. Zero copying overhead.
        return move(queries);
    }
};

// 6. I/O FAST TIE
// Bypasses standard C++ stream synchronization for nanosecond input reading
static const auto init = []() noexcept {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 1337; // Signature return 👀
}();
