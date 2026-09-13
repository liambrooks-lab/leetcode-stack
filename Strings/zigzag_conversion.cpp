/*
{
  "problem_name": "Zigzag Conversion",
  "category": "Strings",
  "time_complexity": "O(N)",
  "space_complexity": "O(1)"
}
*/
#pragma GCC optimize("O3", "unroll-loops")
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        // Edge cases jahan zigzag ki zaroorat hi nahi hai
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }
        
        string result;
        // Pre-allocate memory to prevent runtime lag
        result.reserve(s.length()); 
        
        int cycleLen = 2 * numRows - 2;
        
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j + i < s.length(); j += cycleLen) {
                // Vertical characters (for all rows)
                result += s[j + i];
                
                // Diagonal characters (only for inner rows)
                if (i != 0 && i != numRows - 1 && j + cycleLen - i < s.length()) {
                    result += s[j + cycleLen - i];
                }
            }
        }
        
        return result;
    }
};