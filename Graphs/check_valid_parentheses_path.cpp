/*
{
    "problem_name": "Check if There Is a Valid Parentheses String Path",
    "category": "Graphs / DP / State Space Pruning",
    "time_complexity": "O(m * n * (m + n))",
    "space_complexity": "O(m * n * (m + n))"
}
*/

#pragma GCC optimize("O3", "unroll-loops")

#include <vector>
#include <string>
#include <cstring>

using namespace std;

// Fast I/O desync
auto init = []() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();

class Solution {
    int memo[100][100][201];
    int rows, cols;
    
    bool dfs(int r, int c, int balance, const vector<vector<char>>& grid) {
        // Pruning 1: If balance drops below zero, invalid path
        if (balance < 0) return false;
        
        // Base Case: Reached bottom-right cell (m-1, n-1)
        if (r == rows - 1 && c == cols - 1) {
            // Adjust balance for the final cell and check if it hits absolute zero
            char final_char = grid[r][c];
            int final_balance = (final_char == '(') ? balance + 1 : balance - 1;
            return final_balance == 0;
        }
        
        // Memoization check to avoid overlapping subproblem calculations
        if (memo[r][c][balance] != -1) {
            return memo[r][c][balance];
        }
        
        // Compute new balance for current cell
        char current_char = grid[r][c];
        int next_balance = (current_char == '(') ? balance + 1 : balance - 1;
        
        // Pruning 2: Early exit if balance became negative mid-way
        if (next_balance < 0) return memo[r][c][balance] = 0;
        
        bool possible = false;
        
        // Move Down (r + 1, c)
        if (r + 1 < rows) {
            possible = possible || dfs(r + 1, c, next_balance, grid);
        }
        
        // Move Right (r, c + 1)
        if (!possible && c + 1 < cols) {
            possible = possible || dfs(r, c + 1, next_balance, grid);
        }
        
        return memo[r][c][balance] = possible ? 1 : 0;
    }

public:
    bool hasValidPath(vector<vector<char>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        
        // Max possible path length is rows + cols - 1. Half of that is max open brackets.
        // Initializing memo table with -1 for state tracking
        memset(memo, -1, sizeof(memo));
        
        return dfs(0, 0, 0, grid);
    }
};