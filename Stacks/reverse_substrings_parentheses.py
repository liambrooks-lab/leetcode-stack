"""
{
    "problem_name": "Reverse Substrings Between Each Pair of Parentheses",
    "category": "Stack / O(N) Wormhole Traversal",
    "time_complexity": "O(N)",
    "space_complexity": "O(N)"
}
"""

class Solution:
    def reverseParentheses(self, s: str) -> str:
        n = len(s)
        pair = [0] * n
        stack = []
        
        # Step 1: Pre-compute the portal jumps using a bare-metal stack
        for i, char in enumerate(s):
            if char == '(':
                stack.append(i)
            elif char == ')':
                j = stack.pop()
                pair[i] = j
                pair[j] = i
                
        res = []
        i = 0
        direction = 1
        
        # Step 2: O(N) State-space execution without a single string reversal
        while i < n:
            if s[i] == '(' or s[i] == ')':
                # Teleport to the matching pair and flip the iteration direction
                i = pair[i]
                direction = -direction
            else:
                res.append(s[i])
            
            i += direction
            
        # O(N) native join bypasses string concatenation overhead
        return "".join(res)