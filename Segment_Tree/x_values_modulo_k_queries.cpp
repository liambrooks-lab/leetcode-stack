/*
{
    "problem_name": "Find X-Values of Subarrays Modulo K (Range Queries)",
    "category": "Segment Tree",
    "time_complexity": "O(N + Q \\log N)",
    "space_complexity": "O(N * K)"
}
*/

#include <vector>
#include <array>
#include <cmath>

using namespace std;

class SegmentTree {
private:
    // K is max 5, so size 6 array perfectly holds counts (0 to k-1) AND the total multiplier at index k
    static const int MAXK = 6;
    int k;
    int n;
    
    // Using std::array avoids struct overhead and ensures ultra-fast continuous memory access in L1 Cache
    vector<array<int, MAXK>> tree; 

    // Initializes a leaf node for a single array element
    void makeLeaf(int o, int value) {
        tree[o].fill(0);
        int r = value % k;
        tree[o][r] = 1;      // 1 valid prefix for this remainder
        tree[o][k] = r;      // Index 'k' acts as the total product multiplier for this segment
    }

    // Core State-Space Transition: Merges left and right segment nodes
    void mergePre(const array<int, MAXK>& left, const array<int, MAXK>& right, array<int, MAXK>& result) {
        result.fill(0);
        
        int mulL = left[k];
        int mulR = right[k];
        
        // New multiplier is the product of left and right multipliers modulo k
        result[k] = (mulL * mulR) % k;

        // 1. Inherit all valid prefix remainders straight from the left child
        for (int x = 0; x < k; x++) {
            result[x] = left[x];
        }

        // 2. Extend prefixes from the right child, scaled by the left segment's total product
        for (int x = 0; x < k; x++) {
            result[(mulL * x) % k] += right[x];
        }
    }

    void maintain(int o) {
        mergePre(tree[o * 2], tree[o * 2 + 1], tree[o]);
    }

    void build(const vector<int>& nums, int o, int l, int r) {
        if (l == r) {
            makeLeaf(o, nums[l]);
            return;
        }
        int m = (l + r) / 2;
        build(nums, o * 2, l, m);
        build(nums, o * 2 + 1, m + 1, r);
        maintain(o);
    }

public:
    SegmentTree(const vector<int>& nums, int k) : k(k), n(nums.size()) {
        // Optimal memory allocation: 2 * next power of 2
        int size = 2 << (int)ceil(log2(n));
        tree.resize(size);
        build(nums, 1, 0, n - 1);
    }

    // O(log N) point update
    void update(int o, int l, int r, int index, int value) {
        if (l == r) {
            makeLeaf(o, value);
            return;
        }
        int m = (l + r) / 2;
        if (index <= m) update(o * 2, l, m, index, value);
        else update(o * 2 + 1, m + 1, r, index, value);
        maintain(o);
    }

    // O(log N) range query
    array<int, MAXK> query(int o, int l, int r, int L, int R) {
        if (L <= l && r <= R) {
            return tree[o];
        }
        int m = (l + r) / 2;
        if (R <= m) {
            return query(o * 2, l, m, L, R);
        }
        if (L > m) {
            return query(o * 2 + 1, m + 1, r, L, R);
        }
        
        array<int, MAXK> left = query(o * 2, l, m, L, R);
        array<int, MAXK> right = query(o * 2 + 1, m + 1, r, L, R);
        array<int, MAXK> result;
        mergePre(left, right, result);
        return result;
    }
};

class Solution {
public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n = nums.size();
        SegmentTree seg(nums, k);
        vector<int> ans;
        ans.reserve(queries.size()); // Pre-allocate memory to prevent dynamic resizing overhead

        for (auto& q : queries) {
            int index = q[0], value = q[1], start = q[2], x = q[3];
            
            // Execute live point update
            seg.update(1, 0, n - 1, index, value);
            
            // Fetch segment data and extract the required modulo count
            auto pre = seg.query(1, 0, n - 1, start, n - 1);
            ans.push_back(pre[x]);
        }
        return ans;
    }
};