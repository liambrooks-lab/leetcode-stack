"""
{
    "problem_name": "Minimum Add to Make Parentheses Valid",
    "category": "Greedy / State Tracking",
    "time_complexity": "O(N)",
    "space_complexity": "O(1) - Zero Stack Allocation"
}
"""

class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        open_needed = 0
        close_needed = 0
        
        # Single-pass stateless greedy execution
        for char in s:
            if char == '(':
                # We encountered an open bracket, so we expect a closing bracket later
                close_needed += 1
            elif close_needed > 0:
                # We encountered a closing bracket and we have a pending open bracket to match it
                close_needed -= 1
            else:
                # We encountered a closing bracket, but NO open brackets are available.
                # This means we are forced to insert an '(' right before it.
                open_needed += 1
                
        # Total insertions = unmatched '(' + unmatched ')'
        return open_needed + close_needed