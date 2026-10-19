/*
{
  "problem_name": "Smallest Stable Index",
  "category": "Prefix_Sum",
  "time_complexity": "O(N)",
  "space_complexity": "O(1)"
}
*/

package prefixsum

// SmallestStableIndex identifies the smallest stable index satisfying prefix max minus suffix min bound k.
func SmallestStableIndex(nums []int, k int) int {
	n := len(nums)
	if n == 0 {
		return -1
	}

	minSuffix := make([]int, n)
	mi := nums[n-1]
	minSuffix[n-1] = mi
	for i := n - 2; i >= 0; i-- {
		if nums[i] < mi {
			mi = nums[i]
		}
		minSuffix[i] = mi
	}

	mx := nums[0]
	for i := 0; i < n; i++ {
		if nums[i] > mx {
			mx = nums[i]
		}
		if mx-minSuffix[i] <= k {
			return i
		}
	}

	return -1
}

func smallestStableIndex(nums []int, k int) int {
	return SmallestStableIndex(nums, k)
}
