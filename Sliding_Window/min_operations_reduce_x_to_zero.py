"""
{
    "problem_name": "Minimum Operations to Reduce X to Zero",
    "category": "Sliding Window",
    "time_complexity": "O(N)",
    "space_complexity": "O(1)"
}
"""

from typing import List

class Solution:
    def minOperations(self, nums: List[int], x: int) -> int:
        n = len(nums)
        
        # The Mastermind Flip: Instead of removing from edges to get sum 'x',
        # find the longest contiguous subarray in the middle that sums to 'total - x'
        target = sum(nums) - x
        
        # Edge Case 1: If target is exactly 0, it means we need to remove all elements
        if target == 0:
            return n
        # Edge Case 2: Total sum is less than x, mathematically impossible to reduce x to 0
        elif target < 0:
            return -1

        res = -1
        currsum = 0
        l = 0
        
        # O(N) Sliding Window: Bare-metal pointer tracking without extra memory
        for r in range(n):
            currsum += nums[r]
            
            # State-space pruning: Shrink the window from the left if the sum exceeds our target
            while currsum > target:
                currsum -= nums[l]
                l += 1
            
            # Target locked: Record the maximum length of this core subarray
            if currsum == target:
                res = max(res, (r - l + 1))    
        
        # Minimum edge operations = Total elements - maximum core length
        return n - res if res != -1 else -1