"""
{
  "problem_name": "Rm Element",
  "category": "Two_Pointers",
  "time_complexity": "O(N)",
  "space_complexity": "O(1)"
}
"""
class Solution:
    def removeElement(self, nums: list[int], val: int) -> int:
   
        k = 0
        
        for i in range(len(nums)):
        
            if nums[i] != val:
                nums[k] = nums[i]
                k += 1
    
        return k