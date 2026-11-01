/*
{
    "problem_name": "Minimum Moves to Equal Array Elements",
    "category": "Math / Brainteaser",
    "time_complexity": "O(N) -> Two pure cache-friendly linear scans. Zero branching inside the sum.",
    "space_complexity": "O(1) auxiliary -> No extra memory allocated, executed directly on CPU registers."
}
*/
package main

func minMoves(nums []int) int {
	// 1. Find the absolute minimum element in the array
	minVal := nums[0]
	for _, num := range nums {
		if num < minVal {
			minVal = num
		}
	}

	// 2. Calculate the total relative decrements required
	var moves int
	for _, num := range nums {
		moves += num - minVal
	}

	return moves
}