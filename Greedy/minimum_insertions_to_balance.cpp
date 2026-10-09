/*
{
    "problem_name": "Minimum Insertions to Balance a Parentheses String",
    "category": "Greedy / State Tracking",
    "time_complexity": "O(N)",
    "space_complexity": "O(1) - Pure Register Tracking"
}
*/

#pragma GCC optimize("O3", "unroll-loops")

#include <string>

using namespace std;

// Fast I/O desync to completely bypass LeetCode backend bottlenecks
auto init = []() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();

class Solution {
public:
    int minInsertions(string s) {
        int insertions = 0;
        int needed_right = 0;
        
        for (char c : s) {
            if (c == '(') {
                // State Fix: If we currently need an odd number of right brackets, 
                // it means a previous '(' only got one ')'. We MUST insert a second ')' 
                // right now before opening a new context.
                if (needed_right % 2 != 0) {
                    insertions++;
                    needed_right--;
                }
                // Every new '(' strictly demands two ')'
                needed_right += 2;
            } else { 
                // We found a ')'
                needed_right--;
                
                // State Fix: If needed_right drops below 0, we found a ')' WITHOUT a matching '('.
                if (needed_right < 0) {
                    insertions++; // Insert the missing '('
                    needed_right = 1; // Since we inserted a '(', we now need two ')', but we just consumed the current one, so we only need 1 more.
                }
            }
        }
        
        // Final State Check: Any leftover needed right brackets must be manually inserted
        return insertions + needed_right;
    }
};