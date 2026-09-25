"""
{
    "problem_name": "Brace Expansion II",
    "category": "Stack / Parser",
    "time_complexity": "O(N + K log K) - N is string len, K is output size",
    "space_complexity": "O(K) - Minimal memory footprint"
}
"""

from typing import List

class Solution:
    def braceExpansionII(self, expression: str) -> List[str]:
        stack = []
        # 'res' holds comma-separated sets (to be unioned)
        res = []
        # 'cur' holds the current contiguous string set (to be concatenated)
        cur = {""}

        # Single-pass execution - parsing strictly in O(N)
        for char in expression:
            if char == '{':
                # State-space push: save current progress and dive one level deep
                stack.append((res, cur))
                res = []
                cur = {""}
                
            elif char == '}':
                # 1. Finalize the current level's comma-separated options
                res.append(cur)
                
                # 2. Compute the union of all options inside the braces
                union_set = set()
                for s in res:
                    union_set.update(s)
                
                # 3. State-space pop: restore the previous level and apply Cartesian product
                prev_res, prev_cur = stack.pop()
                res = prev_res
                
                # O(1) set comprehension for lightning-fast cross concatenation
                cur = {p + c for p in prev_cur for c in union_set}
                
            elif char == ',':
                # Add the current concatenated block to union list and reset 'cur'
                res.append(cur)
                cur = {""}
                
            else: 
                # Lowercase letter: immediately concatenate to all active prefixes
                cur = {c + char for c in cur}
        
        # Flush the final top-level sets
        res.append(cur)
        final_set = set()
        for s in res:
            final_set.update(s)
            
        # Return strictly sorted unique combinations
        return sorted(list(final_set))