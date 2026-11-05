/*
{
    "problem_name": "Find the Distance Value Between Two Arrays",
    "category": "Arrays / Binary Search",
    "time_complexity": "O(M log M + N log M) -> In-place sort of arr2 followed by O(log M) binary search per element in arr1.",
    "space_complexity": "O(1) auxiliary -> Pure scalar variables and pointers, zero heap allocations."
}
*/
package main

import "slices"

func findTheDistanceValue(arr1 []int, arr2 []int, d int) int {
	slices.Sort(arr2)
	count := 0

	for _, val := range arr1 {
		l, r := 0, len(arr2)-1
		isValid := true

		// Custom bare-metal binary search to check if ANY element falls in [val - d, val + d]
		for l <= r {
			mid := l + (r-l)/2
			if arr2[mid] >= val-d && arr2[mid] <= val+d {
				isValid = false
				break
			} else if arr2[mid] < val-d {
				l = mid + 1
			} else {
				r = mid - 1
			}
		}

		if isValid {
			count++
		}
	}

	return count
}
