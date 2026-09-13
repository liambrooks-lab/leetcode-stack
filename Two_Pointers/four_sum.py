"""
{
  "problem_name": "Four Sum",
  "category": "Two_Pointers",
  "time_complexity": "O(N)",
  "space_complexity": "O(1)"
}
"""

import bisect
from typing import List

class Solution:
    def fourSum(self, nums: List[int], t: int) -> List[List[int]]:
        nums.sort()
        le = len(nums)
        
        if le < 4: return []
        
        min_sum = sum(nums[:4])
        max_sum = sum(nums[-4:])
        if min_sum == t: return [nums[:4]]
        if max_sum == t: return [nums[-4:]]
        if not (min_sum < t < max_sum): return []
        
        nums = nums[:4] + [nums[i] for i in range(4, le) if nums[i] != nums[i-4]]
        le = len(nums)
        ans = []
        
        k = 0
        while k < le - 3:
            y = nums[k]
            
            if y + nums[k+1] + nums[k+2] + nums[k+3] > t: break
                
            min_y = t - nums[-3] - nums[-2] - nums[-1]
            if y < min_y:
                k = bisect.bisect_left(nums, min_y, k + 1, le - 3)
                continue
                
            h = k + 1
            while h < le - 2:
                x = nums[h]
                
                if y + x + nums[h+1] + nums[h+2] > t: break
                    
                min_x = t - y - nums[-2] - nums[-1]
                if x < min_x:
                    h = bisect.bisect_left(nums, min_x, h + 1, le - 2)
                    continue
                
                l = h + 1
                r = le - 1
                
                rem = t - y - x
                mid_val = rem // 2
                mid_idx = bisect.bisect_right(nums, mid_val, l, r + 1)
                
                if mid_idx <= l and nums[l] > mid_val:
                    break 
                    
                while l < r:
                    vl, vr = nums[l], nums[r]
                    s = y + x + vl + vr
                    
                    if s == t:
                        ans.append([y, x, vl, vr])
                        l += 1
                        while l < r and nums[l] == vl: l += 1
                        r -= 1
                        while l < r and nums[r] == vr: r -= 1
                        
                    elif s < t:
                        req_vl = rem - vr
                        l = bisect.bisect_left(nums, req_vl, l + 1, mid_idx)
                        
                    else:
                        req_vr = rem - vl
                        r = bisect.bisect_right(nums, req_vr, mid_idx, r) - 1
                
                h += 1
                while h < le - 2 and nums[h] == nums[h-1]: h += 1
            
            k += 1
            while k < le - 3 and nums[k] == nums[k-1]: k += 1
            
        return ans