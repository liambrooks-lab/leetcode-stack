"""
{
  "problem_name": "Search Rotated Array",
  "category": "Binary_Search",
  "time_complexity": "O(log N)",
  "space_complexity": "O(1)"
}
"""
class Solution:
    def search(self, nums: list[int], target: int) -> int:
        left, right = 0, len(nums) - 1
        
        while left <= right:
            mid = (left + right) // 2
            
            # Target located directly at mid
            if nums[mid] == target:
                return mid
                
            # Determine if the left half is the strictly sorted one
            if nums[left] <= nums[mid]:
                # Is the target within this sorted left half?
                if nums[left] <= target < nums[mid]:
                    right = mid - 1  # Narrow down to the left half
                else:
                    left = mid + 1   # Target must be in the right half
                    
            # Otherwise, the right half must be the strictly sorted one
            else:
                # Is the target within this sorted right half?
                if nums[mid] < target <= nums[right]:
                    left = mid + 1   # Narrow down to the right half
                else:
                    right = mid - 1  # Target must be in the left half
                    
        # Loop ends without finding the target
        return -1