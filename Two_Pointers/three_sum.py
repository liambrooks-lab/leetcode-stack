"""
{
  "problem_name": "Three Sum",
  "category": "Two_Pointers",
  "time_complexity": "O(N)",
  "space_complexity": "O(1)"
}
"""
class Solution:
    def threeSum(self, nums: list[int]) -> list[list[int]]:
        res = []
        nums.sort()  # Bare-metal C-level sort
        n = len(nums)
        
        for i in range(n - 2):
           
            if nums[i] > 0:
                break
       
            if i > 0 and nums[i] == nums[i - 1]:
                continue
                
            left, right = i + 1, n - 1
            
            while left < right:
                total = nums[i] + nums[left] + nums[right]
                
                if total < 0:
                    left += 1
                elif total > 0:
                    right -= 1
                else:
                    # Match found!
                    res.append([nums[i], nums[left], nums[right]])
                    
                    # Left duplicate bypass
                    left += 1
                    while left < right and nums[left] == nums[left - 1]:
                        left += 1
                        
                    # Right duplicate bypass (Extra optimization!)
                    right -= 1
                    while left < right and nums[right] == nums[right + 1]:
                        right -= 1
                        
        return res