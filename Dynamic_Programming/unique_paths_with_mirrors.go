/*
{
    "problem_name": "Number of Unique Valid Paths (Grid with Mirrors)",
    "category": "Dynamic Programming / Branchless Bit Manipulation",
    "time_complexity": "O(m * n) -> Flawless branchless execution. CPU pipelining is never interrupted by if-else jumps.",
    "space_complexity": "O(1) auxiliary -> Relies on a globally pre-allocated fixed-size array. Zero runtime heap allocations."
}
*/
package main

// Pre-allocated static buffer bound to maximum constraints (n <= 500).
// Completely eliminates dynamic slice allocation overhead per testcase.
var DP [500]int

func uniquePaths(grid [][]int) int {
	const MOD = 1_000_000_007
	
	// Slice the static buffer for the current grid's width and reset its state
	dp := DP[:len(grid[0])]
	clear(dp)
	dp[0] = 1 // Base case: starting point

	for _, row := range grid {
		count := 0 // Tracks 'dpR' (paths coming from the left)
		
		for j, v := range row {
			// v is either 0 (empty) or 1 (mirror).
			// If v=0, mask=0 (0x000...0). If v=1, mask=-1 (0xFFF...F).
			// 'c' takes a snapshot of the current incoming left paths.
			mask, c := -v, count
			
			// If v=0 (mask=0): c &^ 0 == c. Thus, count = c + dp[j] - MOD
			// If v=1 (mask=-1): c &^ -1 == 0. Thus, count = 0 + dp[j] - MOD
			count = c&^mask + dp[j] - MOD
			
			// Branchless Modulo addition:
			// If count is negative (meaning c + dp[j] < MOD), count >> 63 is -1.
			// (-1) & MOD adds MOD back. If positive, count >> 63 is 0, adding nothing.
			count += (count >> 63) & MOD
			
			// Multiplexer via XOR:
			// If v=0 (mask=0): dp[j] = count ^ 0 = count. (dp[j] takes the merged sum).
			// If v=1 (mask=-1): dp[j] = count ^ (count ^ c) = c. (dp[j] gets deflected left-paths 'c').
			dp[j] = count ^ ((count ^ c) & mask)
		}
	}

	return dp[len(grid[0])-1]
}