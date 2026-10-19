/*
{
  "problem_name": "Distinct Subsequences Ii",
  "category": "Dynamic_Programming",
  "time_complexity": "O(N^2)",
  "space_complexity": "O(N)"
}
*/

package dynamicprogramming

// DistinctSubseqII returns the number of distinct, non-empty subsequences of s modulo 10^9 + 7.
func DistinctSubseqII(s string) int {
	const mod = 1_000_000_007

	// Stack-allocated array tracking most recent index where each lowercase letter appeared
	var lastOccurrence [26]int
	for i := range lastOccurrence {
		lastOccurrence[i] = -1
	}

	// Pre-allocated slice for prefix subsequence counts
	n := len(s)
	dp := make([]int, n+1)
	dp[0] = 1

	for i := 0; i < n; i++ {
		charIndex := int(s[i] - 'a')

		dp[i+1] = (dp[i] * 2) % mod

		if lastOccurrence[charIndex] != -1 {
			dp[i+1] = (dp[i+1] - dp[lastOccurrence[charIndex]] + mod) % mod
		}

		lastOccurrence[charIndex] = i
	}

	return (dp[n] - 1 + mod) % mod
}

func distinctSubseqII(s string) int {
	return DistinctSubseqII(s)
}
