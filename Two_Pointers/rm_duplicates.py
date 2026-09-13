"""
{
  "problem_name": "Rm Duplicates",
  "category": "Two_Pointers",
  "time_complexity": "O(N)",
  "space_complexity": "O(1)"
}
"""
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        i=0
        hist=set()
        for n in nums:
            if n in hist:
                continue
            nums[i]=n
            hist.add(n)
            i+=1
        return i
    