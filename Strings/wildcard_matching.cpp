/*
{
  "problem_name": "Wildcard Matching",
  "category": "Strings",
  "time_complexity": "O(N)",
  "space_complexity": "O(1)"
}
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0;
        int starIdx = -1, match = -1;
        int sLen = s.length(), pLen = p.length();
        
        // Traverse the entire input string
        while (i < sLen) {
            // Case 1: Exact match or '?' (single character wildcard)
            if (j < pLen && (p[j] == '?' || p[j] == s[i])) {
                i++;
                j++;
            }
            // Case 2: Found a '*', record its position and assume it matches empty sequence
            else if (j < pLen && p[j] == '*') {
                starIdx = j;
                match = i;
                j++;
            }
            // Case 3: Mismatch occurred, but we have a '*' to fall back on!
            // Backtrack 'j' to just after the '*', and consume one more character of 's'
            else if (starIdx != -1) {
                j = starIdx + 1;
                match++;
                i = match;
            }
            // Case 4: Mismatch and no '*' to save us
            else {
                return false;
            }
        }
        
        // Clean up any trailing '*' in the pattern
        while (j < pLen && p[j] == '*') {
            j++;
        }
        
        // If we reached the end of the pattern, it's a perfect match
        return j == pLen;
    }
};