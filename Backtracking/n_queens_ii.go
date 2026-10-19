/*
{
  "problem_name": "N Queens Ii",
  "category": "Backtracking",
  "time_complexity": "O(2^N)",
  "space_complexity": "O(N)"
}
*/

package backtracking

// TotalNQueens solves the N-Queens II puzzle returning the number of distinct solutions using bitmasking.
func TotalNQueens(n int) int {
	if n <= 0 {
		return 0
	}

	count := 0
	limit := (1 << n) - 1 // Bitmask of 'n' ones

	var backtrack func(cols, posDiag, negDiag int)
	backtrack = func(cols, posDiag, negDiag int) {
		// Base case: All columns are filled
		if cols == limit {
			count++
			return
		}

		// Find all safe positions (1s in binary representation)
		availablePositions := limit & ^(cols | posDiag | negDiag)

		for availablePositions > 0 {
			// Isolate lowest set bit (first available safe spot)
			pos := availablePositions & -availablePositions

			// Remove this spot from available positions
			availablePositions &= availablePositions - 1

			// Recurse to next row: set col bit, shift diagonals
			backtrack(cols|pos, (posDiag|pos)<<1, (negDiag|pos)>>1)
		}
	}

	backtrack(0, 0, 0)
	return count
}

func totalNQueens(n int) int {
	return TotalNQueens(n)
}
