/*
{
  "problem_name": "Merge K Lists",
  "category": "Linked_Lists",
  "time_complexity": "O(N)",
  "space_complexity": "O(1)"
}
*/
/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode[]} lists
 * @return {ListNode}
 */
var mergeKLists = function(lists) {
    if (!lists || lists.length === 0) return null;

    const mergeTwoLists = (l1, l2) => {
        let dummy = new ListNode(-1);
        let current = dummy;
        
        while (l1 !== null && l2 !== null) {
            if (l1.val <= l2.val) {
                current.next = l1;
                l1 = l1.next;
            } else {
                current.next = l2;
                l2 = l2.next;
            }
            current = current.next;
        }
        
        if (l1 !== null) current.next = l1;
        if (l2 !== null) current.next = l2;
        
        return dummy.next;
    };

    let interval = 1;
    while (interval < lists.length) {
        for (let i = 0; i < lists.length - interval; i += interval * 2) {
        
            lists[i] = mergeTwoLists(lists[i], lists[i + interval]);
        }
        interval *= 2;
    }

    return lists[0];
};