/*
{
    "problem_name": "Minimum Total Moves to Equal Array Elements (Single Increment)",
    "category": "Math / Single Pass",
    "time_complexity": "O(N) -> Pure single-pass scan evaluating Sum and Max simultaneously.",
    "space_complexity": "O(1) -> Strictly scalar register variables, zero allocations."
}
*/
package main

func minMoves(nums []int) int {
	maxVal := nums[0]
	sum := 0

	// Hardware-optimized Single Pass
	for _, num := range nums {
		if num > maxVal {
			maxVal = num
		}
		sum += num
	}

	// Mathematical reduction: Moves = (N * Max) - Sum
	// Bypasses the need for a second loop completely.
	return (len(nums) * maxVal) - sum
}