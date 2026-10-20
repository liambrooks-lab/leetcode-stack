/*
{
    "problem_name": "Sortable Integers",
    "category": "Math / Arrays / Prefix Sums",
    "time_complexity": "O(N + σ(N)) - Linear precomputation + O(1) block evaluations. Completely bypasses TLE.",
    "space_complexity": "O(N) - State tracking arrays for prefix max, suffix min, and drops."
}
*/

package main

func sortableIntegers(nums []int) int {
	n := len(nums)

	// Step 1: Precompute Prefix Max for O(1) boundary validation
	prefMax := make([]int, n)
	prefMax[0] = nums[0]
	for i := 1; i < n; i++ {
		if nums[i] > prefMax[i-1] {
			prefMax[i] = nums[i]
		} else {
			prefMax[i] = prefMax[i-1]
		}
	}

	// Step 2: Precompute Suffix Min for O(1) boundary validation
	suffMin := make([]int, n)
	suffMin[n-1] = nums[n-1]
	for i := n - 2; i >= 0; i-- {
		if nums[i] < suffMin[i+1] {
			suffMin[i] = nums[i]
		} else {
			suffMin[i] = suffMin[i+1]
		}
	}

	// Step 3: Precompute internal drops prefix sum for O(1) cyclic checks
	drops := make([]int, n)
	for i := 0; i < n-1; i++ {
		drops[i+1] = drops[i]
		if nums[i] > nums[i+1] {
			drops[i+1]++
		}
	}

	// O(1) state evaluator per partitioned block
	check := func(k int) bool {
		for i := 0; i < n; i += k {
			start := i
			end := i + k

			// Global Sort Integrity: The max element before the boundary must be <= min element after
			if end < n && prefMax[end-1] > suffMin[end] {
				return false
			}

			// Cyclic Order Integrity: At most 1 drop is allowed (including the wrap-around)
			internalDrops := drops[end-1] - drops[start]
			wrapDrop := 0
			if nums[end-1] > nums[start] {
				wrapDrop = 1
			}

			if internalDrops+wrapDrop > 1 {
				return false
			}
		}
		return true
	}

	sum := 0
	// Iterate through all divisors of n efficiently
	for i := 1; i*i <= n; i++ {
		if n%i == 0 {
			if check(i) {
				sum += i
			}
			if i*i != n {
				if check(n / i) {
					sum += (n / i)
				}
			}
		}
	}

	return sum
}