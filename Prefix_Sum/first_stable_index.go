/*
{
  "problem_name": "First Stable Index",
  "category": "Prefix_Sum",
  "time_complexity": "O(N)",
  "space_complexity": "O(1)"
}
*/

package prefixsum

// FirstStableIndex finds the first index i such that max(nums[0..i]) - min(nums[i..n-1]) <= k.
func FirstStableIndex(nums []int, k int) int {
	n := len(nums)
	if n == 0 {
		return -1
	}

	// Contiguous pre-allocated slice for suffix tracking
	minRight := make([]int, n)

	// Phase 1: Suffix Min Precomputation - O(N)
	currentMin := nums[n-1]
	minRight[n-1] = currentMin
	for i := n - 2; i >= 0; i-- {
		if nums[i] < currentMin {
			currentMin = nums[i]
		}
		minRight[i] = currentMin
	}

	// Phase 2: Running Prefix Max & Instant Evaluation - O(N)
	maxLeft := nums[0]
	for i := 0; i < n; i++ {
		if nums[i] > maxLeft {
			maxLeft = nums[i]
		}

		if maxLeft-minRight[i] <= k {
			return i
		}
	}

	return -1
}

func firstStableIndex(nums []int, k int) int {
	return FirstStableIndex(nums, k)
}
