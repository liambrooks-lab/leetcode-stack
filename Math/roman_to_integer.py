"""
{
  "problem_name": "Roman To Integer",
  "category": "Math",
  "time_complexity": "O(N)",
  "space_complexity": "O(1)"
}
"""
class Solution:
    def romanToInt(self, s: str) -> int:
        v={
            'I':1,
            'V':5,
            'X':10,
            'L':50,
            'C':100,
            'D':500,
            'M':1000
        }
        n=0
        for i in range(len(s)):
            if i + 1 < len(s) and v[s[i]] < v[s[i + 1]]:
                n -= v[s[i]]
            else:
                n += v[s[i]]

        return n