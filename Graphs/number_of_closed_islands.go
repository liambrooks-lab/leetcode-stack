/*
{
    "problem_name": "Number of Closed Islands",
    "category": "Graphs / DFS",
    "time_complexity": "O(R * C) -> Bare-metal matrix traversal. Each land cell is visited and mutated exactly once.",
    "space_complexity": "O(1) auxiliary -> In-place grid mutation completely bypasses external visited array allocations."
}
*/
package main

func closedIsland(grid [][]int) int {
	rows := len(grid)
	if rows == 0 {
		return 0
	}
	cols := len(grid[0])

	// DFS closure to aggressively mutate land (0) to water (1) in-place
	var sink func(r, c int)
	sink = func(r, c int) {
		// Out of bounds or already water
		if r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == 1 {
			return
		}
		// Mutate state to prevent redundant visits and save memory
		grid[r][c] = 1
		
		sink(r-1, c) // Up
		sink(r+1, c) // Down
		sink(r, c-1) // Left
		sink(r, c+1) // Right
	}

	// 1. Surgical Strike on Borders: Sink all un-closable boundary islands
	for i := 0; i < rows; i++ {
		if grid[i][0] == 0 {
			sink(i, 0)
		}
		if grid[i][cols-1] == 0 {
			sink(i, cols-1)
		}
	}
	for j := 0; j < cols; j++ {
		if grid[0][j] == 0 {
			sink(0, j)
		}
		if grid[rows-1][j] == 0 {
			sink(rows-1, j)
		}
	}

	// 2. Scan internal matrix for true closed islands
	count := 0
	for i := 1; i < rows-1; i++ {
		for j := 1; j < cols-1; j++ {
			if grid[i][j] == 0 {
				count++
				sink(i, j) // Sink it so we don't count it again
			}
		}
	}

	return count
}