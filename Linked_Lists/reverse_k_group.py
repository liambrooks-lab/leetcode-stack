"""
{
  "problem_name": "Reverse K Group",
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
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        dummy = ListNode(0, head)
        prev_tail = dummy
        curr = head
        
        while curr:
      
            tail = curr
            count = 0
            while tail and count < k:
                tail = tail.next
                count += 1
     
            if count != k:
                prev_tail.next = curr
                break
           
            prev = tail 
            head_of_reversed = curr
            
            for _ in range(k):
        
                curr.next, prev, curr = prev, curr, curr.next
                
      
            prev_tail.next = prev
            prev_tail = head_of_reversed
            
        return dummy.next