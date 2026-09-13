/*
{
  "problem_name": "String To Integer Atoi",
  "category": "Strings",
  "time_complexity": "O(N)",
  "space_complexity": "O(1)"
}
*/
class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.length();
        int sign = 1;
        int result = 0;
        
        // Step 1: Skip leading whitespaces
        while (i < n && s[i] == ' ') {
            i++;
        }
        
        // Step 2: Determine the sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        
        // Step 3: Process digits and handle 32-bit overflow strictly
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';
            
            // The Voxion-Labs Masterstroke: Strict 32-bit boundary check 
            // INT_MAX is 2147483647. If result == 214748364, the next digit can't be > 7
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > 7)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            
            result = result * 10 + digit;
            i++;
        }
        
        return result * sign;
    }
};