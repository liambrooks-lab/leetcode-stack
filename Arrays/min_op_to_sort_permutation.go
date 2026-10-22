/*
{
    "problem_name": "Minimum Operations to Sort a Permutation",
    "category": "Arrays / Math",
    "time_complexity": "O(N) -> Pure linear state-space evaluation. Bypasses hardware modulo division with arithmetic jumps.",
    "space_complexity": "O(1) -> Strict constant space, zero dynamic memory allocations."
}
*/
package main

func minOperations(nums []int) int {
	n := len(nums)
	if n == 1 {
		return 0
	}

	// 1. Locate the absolute anchor (0)
	idx := -1
	for i := 0; i < n; i++ {
		if nums[i] == 0 {
			idx = i
			break
		}
	}

	// 2. Fast Cyclically Increasing (CI) Check
	isCI := true
	for i := 1; i < n; i++ {
		pos := idx + i
		if pos >= n {
			pos -= n // Arithmetic jump bypassing modulo overhead
		}
		if nums[pos] != i {
			isCI = false
			break
		}
	}

	// 3. Fast Cyclically Decreasing (CD) Check
	isCD := true
	for i := 1; i < n; i++ {
		pos := idx - i
		if pos < 0 {
			pos += n // Arithmetic jump bypassing modulo overhead
		}
		if nums[pos] != i {
			isCD = false
			break
		}
	}

	ans := -1

	// 4. Calculate cost if CI
	if isCI {
		cost := idx
		if n-idx+2 < cost {
			cost = n - idx + 2
		}
		if ans == -1 || cost < ans {
			ans = cost
		}
	}

	// 5. Calculate cost if CD
	if isCD {
		cost := idx + 2
		if n-idx < cost {
			cost = n - idx
		}
		if ans == -1 || cost < ans {
			ans = cost
		}
	}

	return ans
}