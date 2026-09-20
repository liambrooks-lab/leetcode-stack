/*
{
    "problem_name": "Reverse Degree of a String",
    "category": "Strings",
    "time_complexity": "O(N)",
    "space_complexity": "O(1)"
}
*/

#include <string>

using namespace std;

class Solution {
public:
    int reverseDegree(string s) {
        int total_degree = 0;
        
        for (int i = 0; i < s.length(); ++i) {
            // ASCII Math: 'z' - s[i] + 1 directly maps 'a' to 26 ... 'z' to 1
            int char_val = 'z' - s[i] + 1;
            
            // 1-indexed position
            int pos_val = i + 1;
            
            total_degree += char_val * pos_val;
        }
        
        return total_degree;
    }
};