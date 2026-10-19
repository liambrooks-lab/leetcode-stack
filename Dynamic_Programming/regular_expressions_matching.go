/*
{
  "problem_name": "Regular Expressions Matching",
  "category": "Dynamic_Programming",
  "time_complexity": "O(N^2)",
  "space_complexity": "O(N)"
}
*/

package dynamicprogramming

// IsMatch implements regular expression matching with support for '.' and '*'.
func IsMatch(s string, p string) bool {
	m := len(s)
	n := len(p)

	// Pre-allocate 1D slices for O(N) space and double-buffering
	dp := make([]bool, n+1)
	nextDp := make([]bool, n+1)

	// Base case: empty string matches empty pattern
	dp[0] = true

	// Handle empty string matching with patterns like "a*b*"
	for j := 1; j <= n; j++ {
		if p[j-1] == '*' {
			dp[j] = dp[j-2]
		}
	}

	for i := 1; i <= m; i++ {
		// Clear nextDp buffer
		for j := 0; j <= n; j++ {
			nextDp[j] = false
		}

		for j := 1; j <= n; j++ {
			if p[j-1] == '*' {
				// 0 occurrences OR (1+ occurrences AND preceding character matches)
				precedingMatch := p[j-2] == s[i-1] || p[j-2] == '.'
				nextDp[j] = nextDp[j-2] || (precedingMatch && dp[j])
			} else if p[j-1] == '.' || p[j-1] == s[i-1] {
				// Exact match or '.' wildcard
				nextDp[j] = dp[j-1]
			}
		}

		// Double-buffer swap
		dp, nextDp = nextDp, dp
	}

	return dp[n]
}

func isMatch(s string, p string) bool {
	return IsMatch(s, p)
}
