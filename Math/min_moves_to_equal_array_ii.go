/*
{
    "problem_name": "Minimum Moves to Equal Array Elements II",
    "category": "Math / L1 Norm Minimization",
    "time_complexity": "O(N log N) -> Execution is dominated by the sorting algorithm. The distance calculation is a pure O(N) scan.",
    "space_complexity": "O(1) auxiliary -> Relies on in-place sorting and scalar accumulators. Zero extra heap overhead."
}
*/
package main

import "sort"

func minMoves2(nums []int) int {
	// 1. Sort the array to align elements monotonically.
	// This enables O(1) access to the statistical median.
	sort.Ints(nums)
	n := len(nums)
	
	// 2. The Golden Target: Median.
	// Mathematically, the median strictly minimizes the sum of absolute deviations (L1 norm).
	// Mean minimizes squared differences (L2 norm), but for uniform +/- 1 moves, median is king.
	mid := nums[n/2]
	res := 0
	
	// 3. O(N) contiguous memory scan to compute total relative distance.
	for _, num := range nums {
		// Bare-metal absolute difference calculation.
		// Deliberately bypassing math.Abs() to avoid expensive int -> float64 -> int typecast cycles.
		if num - mid > 0 {
			res += num - mid
		} else {
			res += mid - num
		}
	}
	
	return res
}