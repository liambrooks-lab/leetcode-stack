class Solution:
    def countCommas(self, n: int) -> int:
        total_commas = 0
        # Iterate through every power of 10 block starting from 4-digit numbers (1000)
        # Up to n = 10^5, numbers can have 4 or 5 digits, meaning they have 1 or 2 commas.
        base = 1000
        comma_count = 1
        
        while base <= n:
            # All numbers from 'base' up to 'n' will contain at least 'comma_count' commas.
            # The count of numbers in this range is (n - base + 1).
            total_commas += (n - base + 1)
            
            # Move to the next threshold where numbers gain an additional comma (e.g., 1,000,000 etc.)
            base *= 1000
            comma_count += 1
            
        return total_commas