/*
{
    "problem_name": "Sum of Squares of Distinct Counts II",
    "category": "Fenwick Tree (Dual-BIT) / DP Math Expansion",
    "time_complexity": "O(N log N) - Bare-metal bitwise hardware jumps",
    "space_complexity": "O(N) - Strictly 2N memory, destroying Segment Tree's 4N allocation"
}
*/

#pragma GCC optimize("O3", "unroll-loops")

#include <vector>
#include <unordered_map>

using namespace std;

// Fast I/O desync for zero-latency execution
auto init = []() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();

class BIT {
public:
    int size;
    // To achieve Range Update & Range Query in a BIT, we need two trees.
    // _tree1 tracks the standard difference array (delta).
    // _tree2 tracks (delta * index) to mathematically reconstruct the prefix sums of the range.
    vector<long long> _tree1;
    vector<long long> _tree2;

    BIT(int n) {
        size = n;
        _tree1.assign(n + 2, 0);
        _tree2.assign(n + 2, 0);
    }

    // bitwise operation to isolate the lowest set bit. Absolute 0ms CPU cost.
    int _lowbit(int index) { return index & -index; }

    // Range Add operation: Add 'delta' to interval [left, right]
    void add(int left, int right, int delta) {
        _add(left, delta);           // Inject +delta at 'left'
        _add(right + 1, -delta);     // Nullify the effect immediately after 'right'
    }

    // Range Query operation: Sum over interval [left, right]
    long long query(int left, int right) {
        return _query(right) - _query(left - 1);
    }

private:
    void _add(int index, int delta) {
        index += 1; // 1-based indexing for BIT
        long long rawIndex = index;
        while (index <= size) {
            _tree1[index] += delta;
            _tree2[index] += rawIndex * delta;
            index += _lowbit(index); 
        }
    }

    long long _query(int index) {
        index += 1;
        long long rawIndex = index + 1;
        if (index > size) {
            index = size;
        }
        long long res = 0;
        while (index > 0) {
            // The algebraic reconstruction of the range sum using the dual trees
            res += rawIndex * _tree1[index] - _tree2[index];
            index -= _lowbit(index); 
        }
        return res;
    }
};

class Solution {
public:
    int sumCounts(vector<int>& A) {
        int n = A.size();
        long long res = 0, cur = 0;
        
        // Allocate space for BIT. Slightly larger bounds to avoid overflow traps.
        BIT bit(n + 10);
        unordered_map<int, int> seen;
        long long mod = 1e9 + 7;
        
        for (int i = 0; i < n; i++) {
            int a = A[i];
            
            // j is the start index of subarrays where 'a' is a brand new distinct element
            int j = (seen.count(a) ? seen[a] : -1) + 1;
            
            // Query the current distinct count sum for the affected subarrays [j, i]
            long long q = bit.query(j, i);
            
            // Algebraic DP Expansion: (x + 1)^2 = x^2 + 2x + 1
            // q * 2 represents the "2x" component.
            // (i - j + 1) represents the "+1" component for each affected subarray.
            cur = (cur + q * 2 + i - j + 1) % mod;
            res = (res + cur) % mod;
            
            // Range update: Increment the distinct count for subarrays starting in [j, i]
            bit.add(j, i, 1);
            
            // Update the last seen index for state tracking
            seen[a] = i;
        }
        return res;
    }
};