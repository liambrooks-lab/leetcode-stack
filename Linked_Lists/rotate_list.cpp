class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // Zero-overhead edge case bypass
        if (!head || !head->next || k == 0) return head;

        // Phase 1: Calculate the exact length and lock onto the tail
        ListNode* tail = head;
        int len = 1;
        while (tail->next) {
            tail = tail->next;
            len++;
        }

        // Phase 2: Modulo optimization to annihilate redundant cycles
        k = k % len;
        if (k == 0) return head;

        // Phase 3: The Ring Topology Hack
        tail->next = head; // Connect tail to head to form a circular list

        // Phase 4: Traverse to the new breaking point
        ListNode* new_tail = head;
        for (int i = 0; i < len - k - 1; i++) {
            new_tail = new_tail->next;
        }

        // Phase 5: Snap the ring and establish the new head
        ListNode* new_head = new_tail->next;
        new_tail->next = nullptr;

        return new_head;
    }
};