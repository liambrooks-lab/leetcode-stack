/*
{
    "problem_name": "Longest Valid Parentheses",
    "category": "Two Pointers",
    "time_complexity": "O(N)",
    "space_complexity": "O(1) - Pure Bare-Metal Execution"
}
*/

// Mastermind Hack 1: Force maximum compiler optimization and unroll loops for instant execution
#pragma GCC optimize("O3", "unroll-loops")

#include <string>
#include <algorithm>

using namespace std;

// Mastermind Hack 2: Desync standard I/O to completely bypass runtime bottlenecks
auto init = []() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0, right = 0, max_len = 0;
        int n = s.length();
        
        // Pass 1: Forward Sweep (Registers only, NO heap memory used)
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                left++;
            } else {
                right++;
            }
            
            // State match: valid substring boundary
            if (left == right) {
                if (max_len < 2 * right) max_len = 2 * right;
            } 
            // Prune state: sequence became invalid, instantly reset
            else if (right > left) {
                left = right = 0;
            }
        }
        
        left = right = 0;
        
        // Pass 2: Reverse Sweep (Catching the leftover valid boundaries)
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '(') {
                left++;
            } else {
                right++;
            }
            
            if (left == right) {
                if (max_len < 2 * left) max_len = 2 * left;
            } else if (left > right) {
                left = right = 0;
            }
        }
        
        return max_len;
    }
};