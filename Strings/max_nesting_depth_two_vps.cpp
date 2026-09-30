/*
{
    "problem_name": "Maximum Nesting Depth of Two Valid Parentheses Strings",
    "category": "Bitwise Math / Memory Allocation",
    "time_complexity": "O(N)",
    "space_complexity": "O(1) auxiliary"
}
*/

#pragma GCC optimize("O3", "unroll-loops")

#include <vector>
#include <string>

using namespace std;

// Fast I/O desync for LeetCode backend
auto init = []() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();

class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.length();
        
        // Mastermind Hack 1: Pre-allocate vector with exact size. 
        // Bypasses all dynamic resizing and push_back() function call overhead.
        vector<int> res(n);
        
        // Mastermind Hack 2: State-less Bitwise Parity Routing
        for (int i = 0; i < n; ++i) {
            // If '(', assign to set 0 or 1 based on index parity (i & 1).
            // If ')', assign to the opposite set using bitwise XOR (^ 1).
            res[i] = (seq[i] == '(') ? (i & 1) : ((i & 1) ^ 1);
        }
        
        return res;
    }
};