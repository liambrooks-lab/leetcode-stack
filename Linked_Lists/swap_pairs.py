"""
{
  "problem_name": "Swap Pairs",
  "category": "Linked_Lists",
  "time_complexity": "O(N)",
  "space_complexity": "O(1)"
}
"""
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
    
        dummy = ListNode(0, head)
        prev = dummy
        
      
        while prev.next and prev.next.next:
          
            first = prev.next
            second = prev.next.next
       
            first.next = second.next
            second.next = first
            prev.next = second
   
            prev = first
            
        return dummy.next     