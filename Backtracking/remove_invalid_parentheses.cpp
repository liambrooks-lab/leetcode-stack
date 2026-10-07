/*
{
    "problem_name": "Remove Invalid Parentheses",
    "category": "DFS / Bidirectional Scan",
    "time_complexity": "O(N^2) - Absolute minimal branching",
    "space_complexity": "O(N) - Zero Hash Sets Allocation"
}
*/

#pragma GCC optimize("O3", "unroll-loops")

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Fast I/O desync for LeetCode backend
auto init = []() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        dfs(s, 0, 0, {'(', ')'}, res);
        return res;
    }

private:
    void dfs(string s, int last_i, int last_j, const vector<char>& par, vector<string>& res) {
        int count = 0;
        for (int i = last_i; i < s.length(); ++i) {
            if (s[i] == par[0]) count++;
            if (s[i] == par[1]) count--;
            if (count >= 0) continue; // Still balanced, keep moving
            
            // Imbalance detected. We need to remove one closing bracket (par[1]).
            for (int j = last_j; j <= i; ++j) {
                //  Prune duplicate states at the root!
                // We only remove a bracket if it's the FIRST of a consecutive identical group.
                if (s[j] == par[1] && (j == last_j || s[j - 1] != par[1])) {
                    dfs(s.substr(0, j) + s.substr(j + 1), i, j, par, res);
                }
            }
            // Halt this branch immediately. All valid removals for this anomaly are handled.
            return; 
        }
        
        // If left-to-right is perfectly valid, we reverse the string and the parenthesis target 
        // to filter out the opposite parity anomalies in a single sweep!
        string reversed = s;
        reverse(reversed.begin(), reversed.end());
        
        if (par[0] == '(') {
            dfs(reversed, 0, 0, {')', '('}, res);
        } else {
            // If we already did the reverse pass, the string is fully sanitized. Save it.
            res.push_back(reversed);
        }
    }
};