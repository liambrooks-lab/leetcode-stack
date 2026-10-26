/*
{
    "problem_name": "Count Islands With Total Value Divisible by K",
    "category": "Graphs / Iterative DFS",
    "time_complexity": "O(m * n) -> Pure bare-metal iterative traversal. Bypasses all recursive call stack allocations.",
    "space_complexity": "O(m * n) worst-case for the stack slice, but completely eliminates deep recursion memory bloat. Immediate sinking prevents duplicate pushes."
}
*/
package main

func countIslands(grid [][]int, k int) int {
	rows := len(grid)
	if rows == 0 {
		return 0
	}
	cols := len(grid[0])
	count := 0

	// Pre-allocate a single stack to reuse memory across all islands
	stack := make([][2]int, 0, 1024)
	
	// Direction arrays for hardware-friendly loop unrolling
	dr := [4]int{1, -1, 0, 0}
	dc := [4]int{0, 0, 1, -1}

	for i := 0; i < rows; i++ {
		for j := 0; j < cols; j++ {
			if grid[i][j] > 0 {
				sum := grid[i][j]
				grid[i][j] = 0 // Sink immediately to prevent redundant pushes
				
				// Reset stack length for the new island without reallocating
				stack = stack[:0] 
				stack = append(stack, [2]int{i, j})

				for len(stack) > 0 {
					// Pop bare-metal style
					curr := stack[len(stack)-1]
					stack = stack[:len(stack)-1]
					r, c := curr[0], curr[1]

					for d := 0; d < 4; d++ {
						nr, nc := r+dr[d], c+dc[d]
						if nr >= 0 && nc >= 0 && nr < rows && nc < cols && grid[nr][nc] > 0 {
							sum += grid[nr][nc]
							grid[nr][nc] = 0 // Sink aggressively before push
							stack = append(stack, [2]int{nr, nc})
						}
					}
				}

				if sum % k == 0 {
					count++
				}
			}
		}
	}

	return count
}