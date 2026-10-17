/*
{
    "problem_name": "Minimum Swaps to Sort by Digit Sum",
    "category": "Bit Manipulation / Cycle Sort",
    "time_complexity": "O(N log N) - 64-bit Primitive Sorting",
    "space_complexity": "O(N) - Single 64-bit array, Zero Struct Overhead"
}
*/

#pragma GCC optimize("O3", "unroll-loops")

#include <vector>
#include <algorithm>
#include <cstdint>

using namespace std;

// Fast I/O desync for zero-latency execution
auto init = []() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        
        // A native array of 64-bit integers sorts insanely faster 
        // than an array of 12-byte structs because it fits perfectly in hardware registers.
        vector<uint64_t> arr(n);
        
        // Step 1: O(N) 64-bit State Packing
        for (int i = 0; i < n; ++i) {
            uint64_t temp = nums[i];
            uint64_t s = 0;
            
            // Extract digits directly via pure ALU operations
            while (temp > 0) {
                s += temp % 10;
                temp /= 10;
            }
            
            // Bit Packing Layout:
            // [Sum: Bits 50-63] | [Value: Bits 20-49] | [Index: Bits 0-19]
            arr[i] = (s << 50) | ((uint64_t)nums[i] << 20) | (uint64_t)i;
        }
        
        // Step 2: O(N log N) Native Primitive Sort
        // Bypasses all lambda/struct comparator overheads!
        sort(arr.begin(), arr.end());
        
        // Step 3: O(N) Graph Cycle Detection via Bit Unpacking
        int swaps = 0;
        vector<bool> visited(n, false);
        
        for (int i = 0; i < n; ++i) {
            if (visited[i]) continue;
            
            // Unpack the original index by masking the lowest 20 bits (0xFFFFF)
            int orig_idx = arr[i] & 0xFFFFF; 
            
            if (orig_idx == i) continue;
            
            int cycle_size = 0;
            int j = i;
            
            // Traverse the anomaly cycle using bare-metal bit masking
            while (!visited[j]) {
                visited[j] = true;
                j = arr[j] & 0xFFFFF; 
                cycle_size++;
            }
            
            // A completely misplaced cycle of size K requires exactly K - 1 swaps
            if (cycle_size > 1) {
                swaps += (cycle_size - 1);
            }
        }
        
        return swaps;
    }
};