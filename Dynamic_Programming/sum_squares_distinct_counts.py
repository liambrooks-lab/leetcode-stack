"""
{
    "problem_name": "Sum of Squares of Distinct Counts",
    "category": "Dynamic Programming / Math Expansion",
    "time_complexity": "O(N^2)",
    "space_complexity": "O(N) - Strictly bounded state arrays"
}
"""

from typing import List

class Solution:
    def sumCounts(self, nums: List[int]) -> int:
        ans = 1
        prev = 1  # Tracks the sum of squares of distinct counts for subarrays ending at i-1
        dp = [1]  # dp[j] holds the distinct count of subarray nums[j...i]
        
        last = {} # Hash map to track the most recent index of each element
        last[nums[0]] = 0
        
        for i in range(1, len(nums)):
            new_dp = [0] * (i + 1)
            ls = last[nums[i]] if nums[i] in last else -1
        
            # If the distinct count 'x' increases by 1, the new square is (x+1)^2 = x^2 + 2x + 1.
            # prev = Sum of x^2
            # 2 * sum(dp[ls + 1:]) = The '2x' component for subarrays where this element is entirely new
            # i - ls = The '+1' component (number of subarrays where this element wasn't seen before)
            cur = prev + 2 * (sum(dp[ls + 1:])) + i - ls
            ans += cur
            
            # State Transition 1: If the start index 'j' is <= last seen index, 
            # the distinct count doesn't change.
            for j in range(ls + 1):
                new_dp[j] = dp[j]
                
            # State Transition 2: If the start index 'j' is strictly after the last seen index,
            # this new element increases the distinct count for these subarrays by 1.
            for j in range(ls + 1, i):
                new_dp[j] = dp[j] + 1
                
            # The subarray containing only the current single element nums[i...i]
            new_dp[-1] = 1

            # Shift current states to previous for the next iteration
            prev = cur
            dp = new_dp
            last[nums[i]] = i
            
        return ans