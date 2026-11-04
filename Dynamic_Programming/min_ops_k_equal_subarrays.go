/*
{
    "problem_name": "Minimum Operations to Make k Subarrays Equal",
    "category": "DP / Fenwick Tree (BIT) / Binary Lifting",
    "time_complexity": "O(N log(N) + K * N) -> N log N for coordinate compressed BIT sliding window, and K*N for the DP transitions.",
    "space_complexity": "O(N) -> Purely flat 1D arrays for DP, BIT, and frequency counting. Zero 2D grid bloat."
}
*/
package main

import "sort"

// Signature updated to strictly return int64 as per LeetCode's backend
func minOperations(nums []int, x int, k int) int64 {
	n := len(nums)

	// 1. Hardware-friendly Coordinate Compression
	sortedNums := make([]int, n)
	copy(sortedNums, nums)
	sort.Ints(sortedNums)

	uniqueVals := make([]int, 0, n)
	for i, v := range sortedNums {
		if i == 0 || v != sortedNums[i-1] {
			uniqueVals = append(uniqueVals, v)
		}
	}

	MAX_VAL := len(uniqueVals)
	
	// Fenwick trees for sliding window frequencies and sums
	countBIT := make([]int, MAX_VAL+2)
	sumBIT := make([]int64, MAX_VAL+2) // Upgraded to int64 to prevent overflow

	getIdx := func(val int) int {
		l, r := 0, MAX_VAL-1
		for l <= r {
			m := l + (r-l)/2
			if uniqueVals[m] == val {
				return m + 1
			} else if uniqueVals[m] < val {
				l = m + 1
			} else {
				r = m - 1
			}
		}
		return 0
	}

	add := func(val int, cnt int) {
		idx := getIdx(val)
		for i := idx; i <= MAX_VAL; i += i & -i {
			countBIT[i] += cnt
			sumBIT[i] += int64(cnt) * int64(val)
		}
	}

	// 2. Binary Lifting directly on the Fenwick Tree to instantly resolve the median
	findKth := func(kTarget int) int {
		idx := 0
		// 2^17 = 131,072 which perfectly covers N <= 100,000
		for i := 17; i >= 0; i-- {
			nextIdx := idx + (1 << i)
			if nextIdx <= MAX_VAL && countBIT[nextIdx] < kTarget {
				idx = nextIdx
				kTarget -= countBIT[idx]
			}
		}
		return uniqueVals[idx]
	}

	queryCount := func(idx int) int {
		res := 0
		for i := idx; i > 0; i -= i & -i {
			res += countBIT[i]
		}
		return res
	}

	querySum := func(idx int) int64 {
		var res int64 = 0
		for i := idx; i > 0; i -= i & -i {
			res += sumBIT[i]
		}
		return res
	}

	// 3. Sliding Window to Precompute Subarray Equalization Costs
	costArray := make([]int64, n) // Upgraded to int64
	var totalSum int64 = 0

	for i := 0; i < n; i++ {
		val := nums[i]
		add(val, 1)
		totalSum += int64(val)

		// Evict the element that falls out of our window size 'x'
		if i >= x {
			outVal := nums[i-x]
			add(outVal, -1)
			totalSum -= int64(outVal)
		}

		if i >= x-1 {
			// Window is fully formed. Median perfectly minimizes L1 Absolute Deviation.
			medVal := findKth((x + 1) / 2)
			medIdx := getIdx(medVal)

			cLow := int64(queryCount(medIdx))
			sLow := querySum(medIdx)
			cUp := int64(x) - cLow
			sUp := totalSum - sLow

			// O(1) Mathematical reduction mapping exactly to prefix aggregates
			costArray[i] = (cLow*int64(medVal) - sLow) + (sUp - cUp*int64(medVal))
		}
	}

	// 4. Memory-optimized DP state tracking (Swapping 1D Vectors)
	const INF int64 = 1e18 // Upgraded to int64
	prevDp := make([]int64, n)

	for j := 1; j <= k; j++ {
		currDp := make([]int64, n)
		for i := 0; i < n; i++ {
			currDp[i] = INF
		}

		for i := j*x - 1; i < n; i++ {
			// Carry forward minimum cost without forming a subarray ending exactly here
			if i > 0 {
				currDp[i] = currDp[i-1]
			}
			
			// Try forming a subarray ending exactly at 'i'
			var prev int64 = 0
			if i >= x {
				prev = prevDp[i-x]
			}
			
			if prev != INF {
				cost := prev + costArray[i]
				if cost < currDp[i] {
					currDp[i] = cost
				}
			}
		}
		prevDp = currDp
	}

	return prevDp[n-1]
}