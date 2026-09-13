"""
{
  "problem_name": "Max Len Substr 2 Occ",
  "category": "Sliding_Window",
  "time_complexity": "O(N)",
  "space_complexity": "O(1)"
}
"""
class Solution:
    def maximumLengthSubstring(self, s: str) -> int:
  
        freq = [0] * 128 
        left = 0
        max_len = 0
        
        for right in range(len(s)):
      
            char_idx = ord(s[right])
            freq[char_idx] += 1
            
            # Agar frequency 2 se cross hui, toh left shrink 
            while freq[char_idx] > 2:
                freq[ord(s[left])] -= 1
                left += 1
                
            # Max length update
            current_len = right - left + 1
            if current_len > max_len:
                max_len = current_len
                
        return max_len