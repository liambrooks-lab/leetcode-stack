/*
{
  "problem_name": "First Missing Positive",
  "category": "Cyclic_Sort",
  "time_complexity": "O(N)",
  "space_complexity": "O(1)"
}
*/

package sorting

// FirstMissingPositive finds the smallest missing positive integer via in-place cyclic sort.
func FirstMissingPositive(nums []int) int {
	n := len(nums)

	for i := 0; i < n; i++ {
		for nums[i] > 0 && nums[i] <= n && nums[nums[i]-1] != nums[i] {
			correctPos := nums[i] - 1
			nums[correctPos], nums[i] = nums[i], nums[correctPos]
		}
	}

	for i := 0; i < n; i++ {
		if nums[i] != i+1 {
			return i + 1
		}
	}

	return n + 1
}

func firstMissingPositive(nums []int) int {
	return FirstMissingPositive(nums)
}
