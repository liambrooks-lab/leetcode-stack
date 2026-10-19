/*
{
  "problem_name": "Permutations Ii",
  "category": "Backtracking",
  "time_complexity": "O(2^N)",
  "space_complexity": "O(N)"
}
*/

package backtracking

import "sort"

// PermuteUnique returns all possible unique permutations of an array that may contain duplicates.
func PermuteUnique(nums []int) [][]int {
	n := len(nums)
	if n == 0 {
		return [][]int{}
	}

	sort.Ints(nums)

	var result [][]int
	used := make([]bool, n)
	path := make([]int, 0, n)

	var backtrack func()
	backtrack = func() {
		if len(path) == n {
			entry := make([]int, n)
			copy(entry, path)
			result = append(result, entry)
			return
		}

		for i := 0; i < n; i++ {
			if used[i] {
				continue
			}

			// State-Space Pruning: skip duplicate element if preceding identical element was not used
			if i > 0 && nums[i] == nums[i-1] && !used[i-1] {
				continue
			}

			used[i] = true
			path = append(path, nums[i])

			backtrack()

			path = path[:len(path)-1]
			used[i] = false
		}
	}

	backtrack()
	return result
}

func permuteUnique(nums []int) [][]int {
	return PermuteUnique(nums)
}
