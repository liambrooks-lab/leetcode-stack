class Solution:
    def myPow(self, x: float, n: int) -> float:
        # Base case for zero power
        if n == 0:
            return 1.0
        
        # Mathematical state transition for negative powers
        if n < 0:
            x = 1.0 / x
            n = -n
            
        res = 1.0
        current_product = x
        
        # Binary Exponentiation State Machine
        while n > 0:
            # If power is odd, accumulate the current product into the result
            if n % 2 == 1:
                res *= current_product
            
            # Square the base and bit-shift (halve) the power for the next state
            current_product *= current_product
            n //= 2
            
        return res