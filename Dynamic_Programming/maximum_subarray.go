/*
{
  "problem_name": "Maximum Subarray",
  "category": "Dynamic_Programming",
  "time_complexity": "O(N^2)",
  "space_complexity": "O(N)"
}
*/

package dynamicprogramming

// MaxSubArray finds the contiguous subarray with the largest sum and returns its sum.
func MaxSubArray(nums []int) int {
	if len(nums) == 0 {
		return 0
	}

	maxSum := nums[0]
	current := nums[0]

	for i := 1; i < len(nums); i++ {
		n := nums[i]
		if current < 0 {
			current = n
		} else {
			current += n
		}

		if current > maxSum {
			maxSum = current
		}
	}

	return maxSum
}

func maxSubArray(nums []int) int {
	return MaxSubArray(nums)
}
