"""
{
    "problem_name": "Maximum Number of Non-Overlapping Substrings",
    "category": "Greedy",
    "time_complexity": "O(N)",
    "space_complexity": "O(1)"
}
"""

from typing import List
from collections import Counter, deque
from math import inf

class Solution:
    def maxNumOfSubstrings(self, s: str) -> List[str]:
        n = len(s)
        counts = Counter(s)
        
        # O(N) mapping of the first and last occurrences of each character
        first = {k: s.find(k) for k in counts}
        last = {k: s.rfind(k) for k in counts}
        
        res = []
        queue = deque()

        # Process each unique character (max 26 iterations)
        for k in counts:
            queue.appendleft([first[k], last[k], counts[k]])
            left, right, total = inf, -inf, 0

            # Merge overlapping intervals using the queue state
            for x, y, z in queue:
                total += z
                left = min(left, x)
                right = max(right, y)
                
                # If the accumulated frequency matches the interval length, it's a valid isolated substring
                if total == right - left + 1:
                    break

            # State-space reset: lock the valid substring and clear queue for the next independent segment
            if total == right - left + 1:
                res.append(s[left:right+1])
                queue = deque()

        return res