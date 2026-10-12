"""
{
  "problem_name": "Maximum Sum of Squares of K Elements",
  "category": "Greedy",
  "time_complexity": "O(N + K)",
  "space_complexity": "O(1)"
}
"""

class Solution:
    def maxSum(self, nums: list[int], k: int) -> int:
        MOD = 10**9 + 7
        bits = [0] * 31

        # Count the set bits available across all numbers.
        for num in nums:
            while num:
                bit = num & -num
                bits[bit.bit_length() - 1] += 1
                num &= num - 1

        ans = 0

        # Build each number using every bit that is still available.
        for _ in range(k):
            num = 0
            for b in range(31):
                if bits[b]:
                    num |= 1 << b
                    bits[b] -= 1

            ans = (ans + num * num) % MOD

        return ans