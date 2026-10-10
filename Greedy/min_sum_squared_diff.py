"""
{
    "problem_name": "Minimum Sum of Squared Difference",
    "category": "Greedy / Bucket Sort",
    "time_complexity": "O(N + max_diff)",
    "space_complexity": "O(max_diff) - Zero Heap Allocation"
}
"""

class Solution:
    def minSumSquareDiff(self, nums1: list[int], nums2: list[int], k1: int, k2: int) -> int:
        k = k1 + k2
        
        # Step 1: Compute absolute differences and check for absolute pruning
        diffs = [abs(a - b) for a, b in zip(nums1, nums2)]
        total_diff = sum(diffs)
        
        # Mastermind Prune: If our total ops exceed the entire difference, we can flatline everything to 0
        if k >= total_diff:
            return 0
            
        # Step 2: Allocate fixed memory buckets based on the maximum constraint (10^5)
        # This completely bypasses the O(N log N) sorting or O(k log N) heap overhead
        max_diff = max(diffs)
        buckets = [0] * (max_diff + 1)
        
        for d in diffs:
            buckets[d] += 1
            
        # Step 3: Greedy state transition from the highest variance downwards
        for d in range(max_diff, 0, -1):
            if buckets[d] > 0:
                if k >= buckets[d]:
                    # We have enough budget to downgrade ALL elements at this severity level
                    k -= buckets[d]
                    buckets[d - 1] += buckets[d]
                    buckets[d] = 0
                else:
                    # We can only downgrade a fraction of them before our budget hits zero
                    buckets[d - 1] += k
                    buckets[d] -= k
                    k = 0
                    break # Budget exhausted, halt execution
                    
        # Step 4: Compute the final bare-metal sum of squares
        ans = 0
        for d in range(max_diff, 0, -1):
            if buckets[d] > 0:
                ans += buckets[d] * (d * d)
                
        return ans