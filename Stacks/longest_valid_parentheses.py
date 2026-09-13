"""
{
  "problem_name": "Longest Valid Parentheses",
  "category": "Stacks",
  "time_complexity": "O(N)",
  "space_complexity": "O(1)"
}
"""

class Solution:
    def longestValidParentheses(self, s: str) -> int:
        stack, maxi = [-1], 0
        for i in range(len(s)):
            if s[i] == "(": stack.append(i)
            else:
                stack.pop()
                if not stack: stack.append(i)
                else: maxi = max(maxi, i - stack[-1])
        return maxi