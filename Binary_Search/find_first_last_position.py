"""
{
  "problem_name": "Find First Last Position",
  "category": "Binary_Search",
  "time_complexity": "O(log N)",
  "space_complexity": "O(1)"
}
"""
class Solution:
    def searchRange(self, nums: list[int], target: int) -> list[int]:
        
        def find_bound(is_first: bool) -> int:
            left, right = 0, len(nums) - 1
            bound = -1
            
            while left <= right:
                mid = (left + right) // 2
                
                if nums[mid] > target:
                    right = mid - 1
                elif nums[mid] < target:
                    left = mid + 1
                else:
                    # Target found! Save the index.
                    bound = mid
                    # If looking for the first position, shrink the right boundary.
                    if is_first:
                        right = mid - 1
                    # If looking for the last position, shrink the left boundary.
                    else:
                        left = mid + 1
                        
            return bound

        # Execute both binary searches independently
        first_pos = find_bound(True)
        
        # Optimization: If the first position isn't found, the target doesn't exist
        if first_pos == -1:
            return [-1, -1]
            
        last_pos = find_bound(False)
        
        return [first_pos, last_pos]