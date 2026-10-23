/*
{
    "problem_name": "Maximum K to Sort a Permutation",
    "category": "Bit Manipulation",
    "time_complexity": "O(N) -> Pure linear scan with zero-state short-circuiting.",
    "space_complexity": "O(1) -> Strict constant space using a single scalar accumulator."
}
*/
package main

func sortPermutation(nums []int) int {
	// Initialize k to -1 (all 1s in two's complement) to act as the universal AND mask
	k := -1
	
	// Iterate through the array. Short-circuit execution if k hits 0 (as x AND 0 is always 0)
	for i := 0; i < len(nums) && k != 0; i++ {
		// Isolate misplaced elements and reduce them into the bitwise mask
		if i != nums[i] { 
			k &= nums[i] 
		}
	}
	
	// If the array was already sorted, k remains -1. max(0, -1) returns the required 0.
	return max(0, k)
}