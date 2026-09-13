/*
{
  "problem_name": "Longest Substring Without Rep Chars",
  "category": "Sliding_Window",
  "time_complexity": "O(N)",
  "space_complexity": "O(1)"
}
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       
        vector<int> last_seen(256, -1);
        
        int max_len = 0;
        int start = 0;
        
        for (int end = 0; end < s.length(); end++) {
        
            if (last_seen[s[end]] >= start) {
              
                start = last_seen[s[end]] + 1;
            }
            
            last_seen[s[end]] = end;
            
            max_len = max(max_len, end - start + 1);
        }
        
        return max_len;
    }
};