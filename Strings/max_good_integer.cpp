/*
{
    "problem_name": "Maximum Good Integer (maxSumOfSquares)",
    "category": "Math / Greedy String Construction",
    "time_complexity": "O(N) - Hardware-level memory fill",
    "space_complexity": "O(N) - Pre-allocated contiguous memory"
}
*/

#pragma GCC optimize("O3", "unroll-loops")

#include <string>

using namespace std;

auto init = []() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();

class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        // Absolute pruning
        if (sum > 9 * num) return "";
        
        string res;
        // Pre-allocate the exact byte size needed. 
        // Zero dynamic resizing overhead.
        res.reserve(num);
        
        int q = sum / 9;
        int r = sum % 9;
        
        // Block memory injection (insanely faster than loops or concatenation)
        res.append(q, '9');
        
        if (r > 0) {
            // Native char arithmetic, bypasses integer-to-string conversion overhead
            res.push_back('0' + r); 
            res.append(num - q - 1, '0');
        } else {
            res.append(num - q, '0');
        }
        
        return res;
    }
};