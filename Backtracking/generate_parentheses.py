"""
{
    "problem_name": "Generate Parentheses",
    "category": "DFS / Explicit State Routing",
    "time_complexity": "O(4^N / sqrt(N)) - Catalan Number Bound",
    "space_complexity": "O(N) - Recursion Stack depth bound"
}
"""

class Solution:
    def generateParenthesis(self, n: int) -> list[str]:
        vals = []
        
        # Mastermind DFS with strictly defined state branches
        def FindVal(l: int, r: int, P: str):
            # State 1: Open brackets limit completely exhausted
            if l == n:
                if r == n:
                    # Absolute base case: String is fully balanced and formed
                    vals.append(P)
                else:
                    # Forced state: Only option left is to close the remaining brackets
                    FindVal(l, r + 1, P + ')')
            
            # State 2: Current string is perfectly balanced
            # State-space prune: We CANNOT add a closing bracket here, only open is valid
            elif l == r:
                FindVal(l + 1, r, P + '(')
                
            # State 3: Unbalanced state (l > r)
            # Full freedom to branch out in both directions
            else:
                FindVal(l + 1, r, P + '(')
                FindVal(l, r + 1, P + ')')
                
        # Initialize execution from ground zero
        FindVal(0, 0, "")
        
        return vals