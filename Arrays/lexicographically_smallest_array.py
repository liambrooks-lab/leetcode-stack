"""
{
  "problem_name": "Lexicographically Smallest Array",
  "category": "Arrays",
  "time_complexity": "O(N)",
  "space_complexity": "O(1)"
}
"""
class Solution:
    def lexicographicallySmallestArray(self, nums: List[int], limit: int) -> List[int]:
        groups=[]
        cur=[]
        d = {}
        for x in sorted(nums):
            if not cur or x-cur[-1] <= limit:
                cur.append(x)
            else:
                groups.append(cur.copy())
                cur = [x]
            d[x] = len(groups)

        groups.append(cur.copy())
        groups = [l[::-1] for l in groups]

        return [groups[d[x]].pop() for x in nums]