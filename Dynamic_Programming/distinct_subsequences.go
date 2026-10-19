/*
{
  "problem_name": "Distinct Subsequences",
  "category": "Dynamic_Programming",
  "time_complexity": "O(N^2)",
  "space_complexity": "O(N)"
}
*/

package dynamicprogramming

// NumDistinct returns the number of distinct subsequences of s which equals t.
func NumDistinct(s string, t string) int {
	m := len(s)
	n := len(t)
	if m < n {
		return 0
	}

	// 1D slice pre-allocation for O(N) space and zero heap fragmentation
	dp := make([]int, n+1)
	dp[0] = 1 // Base case: an empty string 't' can always be formed 1 way

	for i := 1; i <= m; i++ {
		for j := n; j >= 1; j-- {
			if s[i-1] == t[j-1] {
				dp[j] += dp[j-1]
			}
		}
	}

	return dp[n]
}

func numDistinct(s string, t string) int {
	return NumDistinct(s, t)
}
