/*
{
  "problem_name": "Distribute Elements I",
  "category": "Arrays",
  "time_complexity": "O(N)",
  "space_complexity": "O(1)"
}
*/

package arrays

// ResultArray distributes elements between two arrays based on last element comparison.
func ResultArray(nums []int) []int {
	n := len(nums)
	if n <= 2 {
		res := make([]int, n)
		copy(res, nums)
		return res
	}

	// Pre-allocate to prevent dynamic array reallocation and reduce GC overhead
	arr1 := make([]int, 1, n)
	arr1[0] = nums[0]
	arr2 := make([]int, 1, n)
	arr2[0] = nums[1]

	last1 := nums[0]
	last2 := nums[1]

	for i := 2; i < n; i++ {
		val := nums[i]
		if last1 > last2 {
			arr1 = append(arr1, val)
			last1 = val
		} else {
			arr2 = append(arr2, val)
			last2 = val
		}
	}

	return append(arr1, arr2...)
}

func resultArray(nums []int) []int {
	return ResultArray(nums)
}
