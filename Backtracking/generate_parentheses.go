/*
{
  "problem_name": "Gen Parentheses",
  "category": "Backtracking",
  "time_complexity": "O(2^N)",
  "space_complexity": "O(N)"
}
*/

package backtracking

// GenerateParenthesis generates all combinations of well-formed parentheses.
func GenerateParenthesis(n int) []string {
	if n <= 0 {
		return []string{}
	}

	var result []string
	// Pre-allocate byte slice buffer of length 2*n to eliminate string reallocations
	current := make([]byte, 2*n)

	var backtrack func(open, close, idx int)
	backtrack = func(open, close, idx int) {
		if close == n {
			result = append(result, string(current))
			return
		}

		if open < n {
			current[idx] = '('
			backtrack(open+1, close, idx+1)
		}

		if close < open {
			current[idx] = ')'
			backtrack(open, close+1, idx+1)
		}
	}

	backtrack(0, 0, 0)
	return result
}

func generateParenthesis(n int) []string {
	return GenerateParenthesis(n)
}
