/*
{
  "problem_name": "Permutations",
  "category": "Backtracking",
  "time_complexity": "O(2^N)",
  "space_complexity": "O(N)"
}
*/

package backtracking

// Permute generates all possible permutations of an array of distinct integers.
func Permute(nums []int) [][]int {
	n := len(nums)
	if n == 0 {
		return [][]int{}
	}

	// Pre-calculate factorial capacity to allocate result slice in a single operation
	totalPerms := 1
	for i := 2; i <= n; i++ {
		totalPerms *= i
	}
	result := make([][]int, 0, totalPerms)

	var backtrack func(start int)
	backtrack = func(start int) {
		if start == n {
			entry := make([]int, n)
			copy(entry, nums)
			result = append(result, entry)
			return
		}

		for i := start; i < n; i++ {
			// In-place primitive swap
			nums[start], nums[i] = nums[i], nums[start]
			backtrack(start + 1)
			// Backtrack
			nums[start], nums[i] = nums[i], nums[start]
		}
	}

	backtrack(0)
	return result
}

func permute(nums []int) [][]int {
	return Permute(nums)
}
