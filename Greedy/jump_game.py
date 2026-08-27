class Solution:
    def canJump(self, nums: list[int]) -> bool:

        if 0 not in nums[:-1]:
            return True
            
        goal = len(nums) - 1
        for i in range(goal - 1, -1, -1):
            if i + nums[i] >= goal:
                goal = i
                
        return goal == 0