/*
{
  "problem_name": "Longest Nonzero Xor",
  "category": "Bit_Manipulation",
  "time_complexity": "O(N)",
  "space_complexity": "O(1)"
}
*/

package bitmanipulation

// LongestSubsequence calculates the maximum length of a subsequence with a non-zero XOR sum.
func LongestSubsequence(nums []int) int {
	n := len(nums)
	totalXor := 0
	allZero := true

	for _, x := range nums {
		totalXor ^= x
		if x > 0 {
			allZero = false
		}
	}

	if totalXor > 0 {
		return n
	}

	if allZero {
		return 0
	}
	return n - 1
}

func longestSubsequence(nums []int) int {
	return LongestSubsequence(nums)
}
