"""
{
  "problem_name": "Multiply Strings",
  "category": "Strings",
  "time_complexity": "O(N)",
  "space_complexity": "O(1)"
}
"""
class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        if num1 == "0" or num2 == "0":
            return "0"

        n1 = [ord(c) - 48 for c in num1[::-1]]
        n2 = [ord(c) - 48 for c in num2[::-1]]
        
        res = [0] * (len(n1) + len(n2))
        
        # PHASE 1: Raw multiplication with Zero-Skipping Engine
        for i, d1 in enumerate(n1):
            if d1 == 0: 
                continue  # BYPASS ENTIRE INNER LOOP
            for j, d2 in enumerate(n2):
                if d2 == 0: 
                    continue  # BYPASS ADDITION OVERHEAD
                res[i + j] += d1 * d2
                
        # PHASE 2: Single-pass carry resolution
        carry = 0
        for i in range(len(res)):
            total = res[i] + carry
            res[i] = total % 10
            carry = total // 10
            
        while len(res) > 1 and res[-1] == 0:
            res.pop()
            
        return "".join(str(x) for x in res[::-1])