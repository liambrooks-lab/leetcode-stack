"""
{
    "problem_name": "Minimum XOR Path in a Grid",
    "category": "Dynamic Programming / Bit Manipulation",
    "time_complexity": "O(m * n * min(1024, path_length)) -> Highly optimized state evaluation using Python's native Hash Sets.",
    "space_complexity": "O(n * 1024) -> Strictly 1D array of sets. Automatically garbage collected and dynamically sized."
}
"""
from typing import List

class Solution:
    def minCost(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        
        # 1D DP array of sets to store reachable XOR states dynamically
        dp = [set() for _ in range(n)]
        dp[0].add(grid[0][0])
        
        for i in range(m):
            for j in range(n):
                if i == 0 and j == 0:
                    continue
                
                val = grid[i][j]
                next_dp = set()
                
                # Inherit and mutate states from the top cell (same column j)
                if i > 0:
                    for v in dp[j]:
                        next_dp.add(v ^ val)
                
                # Inherit and mutate states from the left cell (previous column j-1)
                if j > 0:
                    for v in dp[j - 1]:
                        next_dp.add(v ^ val)
                
                # Overwrite current column's state dynamically
                dp[j] = next_dp
                
        # The bottom-right cell's set will contain all possible XOR paths. Return the absolute minimum.
        return min(dp[-1])