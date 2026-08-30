"""
Problem: Two Sum
Approach: One-pass Hash Map
Time Complexity: O(N) - Single traversal of the list.
Space Complexity: O(N) - For storing elements in the dictionary.
"""

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        seen = {} 
        
        for i, num in enumerate(nums):
            required = target - num 
            
            if required in seen:
                return [seen[required], i]      
            seen[num] = i  
            
        return []