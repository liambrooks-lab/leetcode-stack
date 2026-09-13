"""
{
  "problem_name": "Combination Sum",
  "category": "Backtracking",
  "time_complexity": "O(2^N)",
  "space_complexity": "O(N)"
}
"""
class Solution:
    def combinationSum(self, candidates, target):
        result = []

        def backtrack(start, remaining, path):
            if remaining == 0:
                result.append(path[:])
                return

            for i in range(start, len(candidates)):
                num = candidates[i]

                if num > remaining:
                    continue

                path.append(num)

                # i, not i + 1, because we can reuse the same number
                backtrack(i, remaining - num, path)

                path.pop()

        backtrack(0, target, [])
        return result