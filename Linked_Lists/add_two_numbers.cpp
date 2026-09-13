/*
{
  "problem_name": "Add Two Numbers",
  "category": "Linked_Lists",
  "time_complexity": "O(N)",
  "space_complexity": "O(1)"
}
*/
/*
 * Problem: Add Two Numbers
 * Approach: Math with Carry (Linked List Traversal)
 * Time Complexity: O(max(N, M)) - Where N and M are the lengths of the lists.
 * Space Complexity: O(max(N, M)) - For constructing the new resulting list.
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = l1;      
        ListNode* tail = nullptr; 
        int carry = 0;
        
        while (l1 || l2 || carry) {
            int sum = carry;
            if (l1) sum += l1->val;
            if (l2) sum += l2->val;
            
            int digit = sum % 10; 
            carry = sum / 10;    
            
            if (l1) {
                l1->val = digit; 
                tail = l1;
                l1 = l1->next;
                if (l2) l2 = l2->next; 
            } 
            else if (l2) {
                tail->next = l2;
                l2->val = digit; 
                tail = l2;
                l2 = l2->next;
            } 
            else {
                
                tail->next = new ListNode(digit); 
                carry = 0; 
            }
        }
        
        return head; 
    }
};