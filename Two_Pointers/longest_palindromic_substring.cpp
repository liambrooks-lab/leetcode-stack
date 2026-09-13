/*
{
  "problem_name": "Longest Palindromic Substring",
  "category": "Two_Pointers",
  "time_complexity": "O(N^2)",
  "space_complexity": "O(1)"
}
*/
#pragma GCC optimize("O3", "unroll-loops")
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() <= 1) return s;
        
        int min_start = 0, max_len = 1;
        int i = 0;
        
        while (i < s.length()) {
            // Early Exit: Agar remaining string possible max palindrome se choti hai
            if (s.length() - i <= max_len / 2) break; 
            
            int left = i, right = i;
            
            // Duplicate Skipping: Ye wala loop tera 99% execution time bacha lega
            while (right < s.length() - 1 && s[right + 1] == s[right]) {
                ++right;
            }
            
            // Agla center duplicate block ke baad se start hoga
            i = right + 1; 
            
            // Expand strictly outward
            while (right < s.length() - 1 && left > 0 && s[right + 1] == s[left - 1]) {
                ++right;
                --left;
            }
            
            // Track the maximum length and starting index
            int new_len = right - left + 1;
            if (new_len > max_len) {
                min_start = left;
                max_len = new_len;
            }
        }
        
        return s.substr(min_start, max_len);
    }
};