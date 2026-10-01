"""
{
    "problem_name": "Valid Parentheses",
    "category": "Stack",
    "time_complexity": "O(N)",
    "space_complexity": "O(N)"
}
"""

class Solution:
    def isValid(self, s: str) -> bool:
        # Absolute state-space pruning for odd-length strings
        if len(s) % 2 != 0:
            return False
            
        stack = []
        # Hash map for O(1) instant bracket resolution
        bracket_map = {')': '(', '}': '{', ']': '['}
        
        for char in s:
            if char in bracket_map:
                # If stack has elements, pop the top. Otherwise, use a dummy character to force a mismatch.
                top_element = stack.pop() if stack else '#'
                
                # If the popped bracket doesn't match the required opening bracket, execution fails
                if bracket_map[char] != top_element:
                    return False
            else:
                # It's an opening bracket, push it into our bare-metal stack
                stack.append(char)
                
        # If the stack is perfectly empty at the end, all brackets were valid
        return not stack