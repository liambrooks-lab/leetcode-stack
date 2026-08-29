class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        length = 0
        
        # Reverse iteration to achieve O(1) space and instantaneous termination
        for i in range(len(s) - 1, -1, -1):
            if s[i] != ' ':
                length += 1
            elif length > 0:
                # Break exactly when the word ends and a new space begins
                break
                
        return length