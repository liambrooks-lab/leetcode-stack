/*
{
    "problem_name": "Maximum Number of Non-overlapping Palindrome Substrings",
    "category": "Greedy",
    "time_complexity": "O(N * K)",
    "space_complexity": "O(1)"
}
*/

#include <string>

using namespace std;

class Solution {
private:
    // Bare-metal inline verification to avoid function overhead
    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
    
public:
    int maxPalindromes(string s, int k) {
        int n = s.length();
        int count = 0;
        
        for (int i = 0; i <= n - k; ) {
            // Optimal Greedy Choice 1: Check exact length 'k'
            if (isPalindrome(s, i, i + k - 1)) {
                count++;
                i += k; // Skip the entire palindrome to avoid overlap
                continue;
            }
            
            // Optimal Greedy Choice 2: Check length 'k + 1'
            if (i + k < n && isPalindrome(s, i, i + k)) {
                count++;
                i += k + 1; // Skip
                continue;
            }
            
            // State-Space moves forward by 1 if no valid core found
            i++;
        }
        
        return count;
    }
};