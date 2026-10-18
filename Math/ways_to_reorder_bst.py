"""
{
    "problem_name": "Number of Ways to Reorder Array to Get Same BST",
    "category": "Math / Combinatorics / Doubly Linked List (Interval Merging)",
    "time_complexity": "O(N) - Bare-metal linear pass",
    "space_complexity": "O(N) - 1D State Tracking Arrays"
}
"""

class Solution:
    def numOfWays(self, nums: list[int]) -> int:
        MOD = 1_000_000_007
        n = len(nums)
        
        # Simulating a Doubly Linked List to track contiguous intervals in O(1)
        # prev[i] points to the left boundary of the interval
        # next[i] points to the right boundary of the interval
        prev = [i - 1 for i in range(n + 2)]
        next = [i + 1 for i in range(n + 2)]

        # Tracks the size of the subtree rooted at 'x'
        size = [0] * (n + 2)

        # Denominator for our topological sort formula: Product of all subtree sizes
        mul = 1

        # Process from leaves to root (bottom-up tree reconstruction)
        for x in reversed(nums):
            # A single node forms a subtree of size 1
            size[x] = 1

            # Step 1: Check if there's an existing left child/subtree
            left = prev[x]
            if size[left] > 0:
                size[x] += size[left]  # Absorb left subtree size
                
                # Merge intervals: Update the left boundary of our new contiguous block
                pl = prev[left]
                prev[x] = pl
                next[pl] = x

            # Step 2: Check if there's an existing right child/subtree
            right = next[x]
            if size[right] > 0:
                size[x] += size[right] # Absorb right subtree size
                
                # Merge intervals: Update the right boundary of our new contiguous block
                nr = next[right]
                prev[nr] = x
                next[x] = nr

            # Accumulate the product of sizes for the denominator
            mul = (mul * size[x]) % MOD

        # Step 3: Compute N! (Numerator of the topological sort formula)
        fac = 1 
        for i in range(2, n + 1):
            fac = (fac * i) % MOD

        # Math: Ways = N! * (Product of sizes)^-1 % MOD
        # Using Fermat's Little Theorem for modular multiplicative inverse via pow(mul, -1, MOD)
        # Subtract 1 because the problem asks for *other* ways excluding the original array
        return (fac * pow(mul, -1, MOD) - 1) % MOD