/*
	{
	    "problem_name": "Process Tasks Using Servers",
	    "category": "Time Wheel / Hierarchical Bitset / Bucket Sort",
	    "time_complexity": "O(N + M) -> Strictly linear. Bypasses O(log N) heaps entirely using O(1) bitwise trailing zeros and O(1) time-wheel lookups.",
	    "space_complexity": "O(max(N, W)) -> Massive static arrays pre-allocated globally. Zero heap allocations during runtime."
	}
*/
package main

import "math/bits"

const MAXN = 200_002
const W = 200_001

// Global static memory blocks to prevent any runtime GC overhead
var freq, idx, head, nxt [MAXN]uint32
var free, wheel = &HiBitset{}, &HiBitset{}

// cyclic distance to handle array wrap-around in the Time Wheel
func dist(to, from int) int {
	if to < from {
		return to - from + W
	}
	return to - from
}

// O(1) lookup for the next busy time slot using the HiBitset wheel
func getbusy(from int) int {
	if s := wheel.Next(from); s >= 0 {
		return s
	}
	return wheel.Next(0)
}

func assignTasks(servers []int, tasks []int) []int {
	n, maxv := len(servers), 0

	// 1. O(N) Bucket Sort (Radix Counting) for servers instead of O(N log N) QuickSort
	for _, w := range servers {
		maxv = max(maxv, w)
		freq[w]++
	}
	var sum uint32
	for w := range maxv + 1 {
		freq[w], sum = sum, sum+freq[w]
	}
	for i, w := range servers {
		idx[freq[w]] = uint32(i) // idx maps sorted rank -> original server index
		free.Set(int(freq[w]))   // Mark this ranked server as free in the Bitset
		freq[w]++
	}
	clear(freq[:maxv+1])

	last, maxw := 0, 0

	// 2. Time-Wheel Release Engine
	// Frees servers that have completed their tasks up to time 't'
	release := func(t int) {
		from := (last + 1) % W
		for {
			s := getbusy(from)
			if s < 0 || last+1+dist(s, from) > t {
				break // Stop if no busy servers or their completion time is in the future
			}
			// Traverse the CSR bucket for time 's' and free all servers
			for r := head[s]; r != 0; r = nxt[r-1] {
				free.Set(int(r - 1))
			}
			head[s] = 0
			wheel.Unset(s) // Mark this time slot as empty
		}
		last = t
	}

	t := 0
	for j, d := range tasks {
		t = max(t, j)
		release(t)

		r := free.Next(0) // O(1) Hardware-level fetch of the best available server

		// 3. Fast-Forward Time
		// If no servers are free, instantly jump time to the next busy server's completion
		if r < 0 {
			from := (last + 1) % W
			t = last + 1 + dist(getbusy(from), from)
			release(t)
			r = free.Next(0)
		}

		free.Unset(r) // Mark server as busy

		s := (t + d) % W // Calculate cyclic completion time
		maxw = max(maxw, s)

		// CSR (Compressed Sparse Row) logic to queue the server at completion time 's'
		nxt[r] = head[s]
		head[s] = uint32(r + 1)
		wheel.Set(s)

		tasks[j] = int(idx[r]) // Overwrite tasks array to save memory
	}

	// Cleanup global state for LeetCode's multi-testcase runner
	clear(head[:maxw+1])
	wheel.Clear(maxw)
	free.Clear(n - 1)

	return tasks
}

// --- HIERARCHICAL BITSET (64-ary Tree Engine) ---
// Compresses data so that 1 bit in L1 represents 64 bits in L2.
const HSHIFT = 6
const HMASK = 1<<HSHIFT - 1
const L2 = (MAXN + HMASK) >> HSHIFT
const L1 = (L2 + HMASK) >> HSHIFT
const L0 = (L1 + HMASK) >> HSHIFT

type HiBitset struct {
	l2   [L2]uint64
	l1   [L1]uint64
	l0   uint64
	maxv int
}

// Sets a bit and propagates the "not empty" state up the hierarchy
func (h *HiBitset) Set(v int) {
	idx2 := v >> HSHIFT
	idx1 := idx2 >> HSHIFT
	h.l2[idx2] |= 1 << (v & HMASK)
	h.l1[idx1] |= 1 << (idx2 & HMASK)
	h.l0 |= 1 << (idx1 & HMASK)
}

// Unsets a bit and propagates the "empty" state up the hierarchy if a 64-block empties out
func (h *HiBitset) Unset(v int) {
	idx2 := v >> HSHIFT
	idx1 := idx2 >> HSHIFT
	h.l2[idx2] &^= 1 << (v & HMASK)
	if h.l2[idx2] == 0 {
		h.l1[idx1] &^= 1 << (idx2 & HMASK)
		if h.l1[idx1] == 0 {
			h.l0 &^= 1 << (idx1 & HMASK)
		}
	}
}

// Hardware-accelerated O(1) search for the next set bit >= v using bits.TrailingZeros64
func (h *HiBitset) Next(v int) int {
	idx2 := v >> HSHIFT
	idx1 := idx2 >> HSHIFT
	if next := h.l2[idx2] & (^uint64(0) << (v & HMASK)); next != 0 {
		return (v &^ HMASK) | bits.TrailingZeros64(next)
	}
	if next := h.l1[idx1] & (^uint64(0) << ((idx2 & HMASK) + 1)); next != 0 {
		next2 := (idx1 << HSHIFT) | bits.TrailingZeros64(next)
		return (next2 << HSHIFT) | bits.TrailingZeros64(h.l2[next2])
	}
	if next := h.l0 & (^uint64(0) << ((idx1 & HMASK) + 1)); next != 0 {
		next1 := bits.TrailingZeros64(next)
		next2 := (next1 << HSHIFT) | bits.TrailingZeros64(h.l1[next1])
		return (next2 << HSHIFT) | bits.TrailingZeros64(h.l2[next2])
	}
	return -1
}

// Hardware-accelerated O(1) search for the prev set bit < v using bits.Len64
func (h *HiBitset) Prev(v int) int {
	idx2 := v >> HSHIFT
	idx1 := idx2 >> HSHIFT
	if prev := h.l2[idx2] & ((1 << (v & HMASK)) - 1); prev != 0 {
		return (v &^ HMASK) | (bits.Len64(prev) - 1)
	}
	if prev := h.l1[idx1] & ((1 << (idx2 & HMASK)) - 1); prev != 0 {
		prev2 := (idx1 << HSHIFT) | (bits.Len64(prev) - 1)
		return (prev2 << HSHIFT) | (bits.Len64(h.l2[prev2]) - 1)
	}
	if prev := h.l0 & ((1 << idx1) - 1); prev != 0 {
		prev1 := bits.Len64(prev) - 1
		prev2 := (prev1 << HSHIFT) | (bits.Len64(h.l1[prev1]) - 1)
		return (prev2 << HSHIFT) | (bits.Len64(h.l2[prev2]) - 1)
	}
	return -1
}

func (h *HiBitset) Clear(maxv int) {
	idx := maxv >> HSHIFT
	clear(h.l2[:idx+1])
	clear(h.l1[:idx>>HSHIFT+1])
	h.l0 = 0
}
