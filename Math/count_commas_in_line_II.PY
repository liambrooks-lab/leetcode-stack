class Solution:
    def countCommas(self, n: int) -> int:
        total_commas = 0
        base = 1000
        
        # This O(log N) engine will crush the 10^15 constraint in exactly 5 operations
        while base <= n:
            total_commas += (n - base + 1)
            base *= 1000
            
        return total_commas