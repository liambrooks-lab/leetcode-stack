"""
{
  "problem_name": "Letter Combinations",
  "category": "Backtracking",
  "time_complexity": "O(2^N)",
  "space_complexity": "O(N)"
}
"""
class Solution:
    def letterCombinations(self, digits: str) -> list[str]:
      
        if not digits:
            return []
        

        phone_map = {
            '2': 'abc', '3': 'def', '4': 'ghi', '5': 'jkl',
            '6': 'mno', '7': 'pqrs', '8': 'tuv', '9': 'wxyz'
        }
        
        res = []
     
        def backtrack(index, current_str):
            
            if index == len(digits):
                res.append(current_str)
                return
            current_digit = digits[index]
            for letter in phone_map[current_digit]:
                
                backtrack(index + 1, current_str + letter)
                
        backtrack(0, "")
        
        return res