"""
{
  "problem_name": "Count And Say",
  "category": "Strings",
  "time_complexity": "O(N)",
  "space_complexity": "O(1)"
}
"""
class Solution:
    def countAndSay(self, n: int) -> str:
        # Base case
        if n == 1:
            return "1"
        
        # Start with the first term
        result = "1"
        
        # Iteratively generate the sequence up to n
        for _ in range(2, n + 1):
            next_seq = []
            count = 1
            
            # Scan the current result to generate the next one
            for j in range(1, len(result)):
                if result[j] == result[j - 1]:
                    count += 1
                else:
                    # Character changed, append the run-length and the character
                    next_seq.append(str(count))
                    next_seq.append(result[j - 1])
                    count = 1  # Reset count for the new character
            
            # Append the very last group of characters
            next_seq.append(str(count))
            next_seq.append(result[-1])
            
            # Update result efficiently using join
            result = "".join(next_seq)
            
        return result