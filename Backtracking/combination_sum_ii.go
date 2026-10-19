/*
{
  "problem_name": "Combination Sum Ii",
  "category": "Backtracking",
  "time_complexity": "O(2^N)",
  "space_complexity": "O(N)"
}
*/

package backtracking

import "sort"

// CombinationSum2 finds all unique combinations in candidates where the candidate numbers sum to target.
func CombinationSum2(candidates []int, target int) [][]int {
	// Strict numeric sort for aggressive pruning
	sort.Ints(candidates)

	var result [][]int
	length := len(candidates)
	currentPath := make([]int, 0, length)

	var backtrack func(startIdx, currentTarget int)
	backtrack = func(startIdx, currentTarget int) {
		if currentTarget == 0 {
			entry := make([]int, len(currentPath))
			copy(entry, currentPath)
			result = append(result, entry)
			return
		}

		for i := startIdx; i < length; i++ {
			num := candidates[i]

			// PRUNING 1: Break instantly if the number exceeds our target
			if num > currentTarget {
				break
			}

			// PRUNING 2: Eliminate duplicate subset branches instantly
			if i > startIdx && num == candidates[i-1] {
				continue
			}

			currentPath = append(currentPath, num)
			backtrack(i+1, currentTarget-num)
			currentPath = currentPath[:len(currentPath)-1]
		}
	}

	backtrack(0, target)
	return result
}

func combinationSum2(candidates []int, target int) [][]int {
	return CombinationSum2(candidates, target)
}
