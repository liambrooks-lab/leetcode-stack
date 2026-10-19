/*
{
  "problem_name": "Merge Two Lists",
  "category": "Linked_Lists",
  "time_complexity": "O(N)",
  "space_complexity": "O(1)"
}
*/

package linkedlists

// MergeTwoLists merges two sorted linked lists and returns it as a sorted list.
func MergeTwoLists(list1 *ListNode, list2 *ListNode) *ListNode {
	dummy := &ListNode{Val: -1}
	current := dummy

	for list1 != nil && list2 != nil {
		if list1.Val <= list2.Val {
			current.Next = list1
			list1 = list1.Next
		} else {
			current.Next = list2
			list2 = list2.Next
		}
		current = current.Next
	}

	if list1 != nil {
		current.Next = list1
	} else {
		current.Next = list2
	}

	return dummy.Next
}

func mergeTwoLists(list1 *ListNode, list2 *ListNode) *ListNode {
	return MergeTwoLists(list1, list2)
}
