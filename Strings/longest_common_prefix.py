"""
{
  "problem_name": "Longest Common Prefix",
  "category": "Strings",
  "time_complexity": "O(N)",
  "space_complexity": "O(1)"
}
"""
class Solution:
    def longestCommonPrefix(self, strs: list[str]) -> str:
        if not strs:
            return ""
        prefix = strs[0]
        for s in strs[1:]:
            while not s.startswith(prefix):
                prefix = prefix[:-1]
                if not prefix:
                    return ""
        return prefix