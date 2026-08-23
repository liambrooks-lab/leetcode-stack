class Solution {
public:
    bool isPalindrome(int x) {
        // Edge Case 1: Negative numbers can never be palindromes (-121 != 121-)
        // Edge Case 2: Numbers ending with 0 cannot be palindromes (unless the number is 0 itself)
        if (x < 0 || (x != 0 && x % 10 == 0)) {
            return false;
        }
        
        int reversedHalf = 0;
        
        // Loop runs only until we reach the middle of the number
        while (x > reversedHalf) {
            reversedHalf = reversedHalf * 10 + x % 10;
            x /= 10;
        }
        
        // Even length numbers: x == reversedHalf (e.g., 1221 -> 12 == 12)
        // Odd length numbers: x == reversedHalf / 10 (e.g., 12321 -> 12 == 123/10 -> 12 == 12)
        // We divide by 10 to drop the middle digit since it doesn't matter in a palindrome!
        return x == reversedHalf || x == reversedHalf / 10;
    }
};