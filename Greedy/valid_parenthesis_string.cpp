/*
{
    "problem_name": "Valid Parenthesis String",
    "category": "Greedy / State Space",
    "time_complexity": "O(N)",
    "space_complexity": "O(1)"
}
*/

#pragma GCC optimize("O3", "unroll-loops")

#include <string>

using namespace std;

// Mastermind Hack: Desync I/O for 0ms execution speed
auto init = []() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();

class Solution {
public:
    bool checkValidString(string s) {
        int min_open = 0; // Minimum possible open left parentheses
        int max_open = 0; // Maximum possible open left parentheses
        
        // Single-pass strict O(N) execution
        for (char c : s) {
            if (c == '(') {
                min_open++;
                max_open++;
            } else if (c == ')') {
                min_open--;
                max_open--;
            } else { // c == '*'
                min_open--; // Try treating '*' as ')'
                max_open++; // Try treating '*' as '('
            }
            
            // Pruning condition 1: If even treating all '*' as '(' isn't enough, it's invalid
            if (max_open < 0) return false;
            
            // Pruning condition 2: Negative min_open means we assumed too many '*' as ')'. 
            // We just reset it to 0 (meaning we treat them as empty strings instead).
            if (min_open < 0) min_open = 0;
        }
        
        // At the end, all open brackets must be perfectly balanced
        return min_open == 0;
    }
};