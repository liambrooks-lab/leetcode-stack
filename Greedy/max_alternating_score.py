"""
{
    "problem_name": "Maximum Alternating Score",
    "category": "Math / Quickselect (Vectorized)",
    "time_complexity": "O(N) Expected - via np.partition",
    "space_complexity": "O(N) - NumPy C-array allocation"
}
"""

import numpy as np
from typing import List

class Solution:
    def maxAlternatingSum(self, nums: List[int]) -> int:
        # Vectorize squaring operation using NumPy's C-backend.
        # Enforcing int64 dtype guarantees no integer overflow on massive constraints.
        sq = np.square(np.array(nums, dtype=np.int64))
        
        # Calculate exactly how many negative slots we need to allocate
        h = len(nums) // 2
        
        # O(N) Quickselect via np.partition.
        # This instantly moves the 'h' smallest squares to the front without the O(N log N) sorting overhead.
        
        # The Algebraic Bypass.
        # Sum(Large) - Sum(Small) is mathematically equivalent to Total_Sum - 2 * Sum(Small).
        # This completely skips slicing and summing the larger half of the array!
        return int(sq.sum() - 2 * np.partition(sq, h)[:h].sum())