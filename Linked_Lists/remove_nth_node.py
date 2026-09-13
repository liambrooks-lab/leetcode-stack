"""
{
  "problem_name": "Remove Nth Node",
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
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
 
        dummy = ListNode(0, head)
        slow = dummy
        fast = dummy
        
       
        for _ in range(n + 1):
            fast = fast.next
            
        while fast is not None:
            slow = slow.next
            fast = fast.next
   
        slow.next = slow.next.next

        return dummy.next