"""
{
  "problem_name": "Three Sum Closest",
  "category": "Two_Pointers",
  "time_complexity": "O(N)",
  "space_complexity": "O(1)"
}
"""
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        n = len(nums)
        best = nums[0] + nums[1] + nums[2]
        best_diff = abs(best - target)

        for i in range(n - 2):
            x = nums[i]
            if i > 0 and x == nums[i - 1]:
                continue

    
            min_sum = x + nums[i + 1] + nums[i + 2]
            if min_sum >= target:
                diff = min_sum - target
                if diff < best_diff:
                    best_diff = diff
                    best = min_sum
                break

    
            max_sum = x + nums[-2] + nums[-1]
            if max_sum <= target:
                diff = target - max_sum
                if diff < best_diff:
                    best_diff = diff
                    best = max_sum
                continue

            l, r = i + 1, n - 1
            while l < r:
                s = x + nums[l] + nums[r]
                diff = s - target
                if diff == 0:
                    return s
                if abs(diff) < best_diff:
                    best_diff = abs(diff)
                    best = s
                if diff < 0:
                    l += 1
                    while l < r and nums[l] == nums[l - 1]:
                        l += 1
                else:
                    r -= 1
                    while l < r and nums[r] == nums[r + 1]:
                        r -= 1

        return best