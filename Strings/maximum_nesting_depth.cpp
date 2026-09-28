/*
{
    "problem_name": "Maximum Nesting Depth of the Parentheses",
    "category": "Strings / State Machine",
    "time_complexity": "O(N)",
    "space_complexity": "O(1)"
}
*/

#pragma GCC optimize("O3", "unroll-loops")

#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int current_depth = 0;
        int max_depth = 0;
        
        // Single-pass raw traversal directly matching characters
        for (char c : s) {
            if (c == '(') {
                current_depth++;
                if (current_depth > max_depth) {
                    max_depth = current_depth;
                }
            } else if (c == ')') {
                current_depth--;
            }
        }
        
        return max_depth;
    }
};