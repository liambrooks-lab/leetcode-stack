"""
{
    "problem_name": "Smallest Index With Equal Sum",
    "category": "Math",
    "time_complexity": "O(1)",
    "space_complexity": "O(1)"
}
"""

from typing import List

class Solution:
    def smallestIndex(self, nums: List[int]) -> int:
        for i, num in enumerate(nums):
            # Hack 1: Absolute State-Space Pruning (Max digit sum for 1000 is 27)
            if i > 27:
                return -1
                
            # Hack 2: Number Theory Filter (Digit sum & number share the same Modulo 9)
            if num % 9 != i % 9:
                continue
                
            # Python C-API execution (Fastest way in Python to sum digits)
            if sum(map(int, str(num))) == i:
                return i
                
        return -1