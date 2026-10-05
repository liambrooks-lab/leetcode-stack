"""
{
    "problem_name": "Score of Parentheses",
    "category": "Math / Bitwise",
    "time_complexity": "O(N)",
    "space_complexity": "O(1) - Zero Stack Allocation"
}
"""

class Solution:
    def scoreOfParentheses(self, s: str) -> int:
        score = 0
        depth = 0
        
        # Single-pass execution without any auxiliary data structures
        for i in range(len(s)):
            if s[i] == '(':
                # We go one level deeper into the parentheses tree
                depth += 1
            else:
                # We step out one level
                depth -= 1
                
                # Mastermind Hack: Only calculate score at the absolute leaf nodes '()'
                if s[i-1] == '(':
                    # Bitwise shift is the fastest way to compute 2^depth in any compiler
                    score += 1 << depth
                    
        return score