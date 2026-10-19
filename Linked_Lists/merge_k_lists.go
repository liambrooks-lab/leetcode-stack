/*
{
  "problem_name": "Merge K Lists",
  "category": "Linked_Lists",
  "time_complexity": "O(N)",
  "space_complexity": "O(1)"
}
*/

package linkedlists

// ListNode defines a node in a singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

// MergeKLists merges k sorted linked lists in-place using divide-and-conquer.
func MergeKLists(lists []*ListNode) *ListNode {
	if len(lists) == 0 {
		return nil
	}

	mergeTwoLists := func(l1, l2 *ListNode) *ListNode {
		dummy := &ListNode{Val: -1}
		current := dummy

		for l1 != nil && l2 != nil {
			if l1.Val <= l2.Val {
				current.Next = l1
				l1 = l1.Next
			} else {
				current.Next = l2
				l2 = l2.Next
			}
			current = current.Next
		}

		if l1 != nil {
			current.Next = l1
		} else {
			current.Next = l2
		}

		return dummy.Next
	}

	interval := 1
	for interval < len(lists) {
		for i := 0; i < len(lists)-interval; i += interval * 2 {
			lists[i] = mergeTwoLists(lists[i], lists[i+interval])
		}
		interval *= 2
	}

	return lists[0]
}

func mergeKLists(lists []*ListNode) *ListNode {
	return MergeKLists(lists)
}
