/*
{
    "problem_name": "Remove Outermost Parentheses",
    "category": "Strings / State Tracking",
    "time_complexity": "O(N)",
    "space_complexity": "O(N) - Result string allocation"
}
*/

#pragma GCC optimize("O3", "unroll-loops")

#include <string>

using namespace std;

// Fast I/O desync for zero-latency LeetCode backend execution
auto init = []() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();

class Solution {
public:
    string removeOuterParentheses(string s) {
        int open = 0; // State tracker for nested depth
        string result = "";

        // Single-pass stateless boundary filter
        for (char ch : s) {
            if (ch == '(') {
                // If open > 0, it's an inner bracket. Safely append it.
                // If open == 0, it's the outermost boundary limit. Drop it entirely.
                if (open > 0) result += '(';
                open++; // Ascend into the next depth level
            }
            else {
                open--; // Descend from the current depth level
                // If open > 0 after decrement, we haven't hit the outermost boundary yet.
                if (open > 0) result += ')';
            }
        }

        return result;
    }
};