"""
{
    "problem_name": "Sum of Squares of Special Elements",
    "category": "Math / Arrays",
    "time_complexity": "O(N)",
    "space_complexity": "O(1) - Zero Auxiliary Memory"
}
"""

from typing import List

class Solution:
    def sumOfSquares(self, nums: List[int]) -> int:
        total_sum = 0
        n = len(nums)
        
        # 1-indexed range directly maps to the problem statement.
        # This completely bypasses complex zero-indexed math translations.
        for i in range(1, n + 1):
            # State Check: If 'i' perfectly divides 'n', it's a special element
            if n % i == 0:
                # Map the 1-indexed 'i' back to the 0-indexed array
                val = nums[i - 1]
                # Micro-optimization: Direct multiplication (val * val) is faster than power (val ** 2)
                total_sum += val * val
                
        return total_sum