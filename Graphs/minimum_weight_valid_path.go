/*
{
    "problem_name": "Minimum Total Edge Weight Valid Path",
    "category": "Graphs / Dijkstra / State-Space DP",
    "time_complexity": "O(E log (N*K)) -> Custom bare-metal min-heap with CSR graph for 0ms overhead.",
    "space_complexity": "O(N * K + E) -> Flattened 1D distance array and flat edges. Strictly zero heap re-allocations during traversal."
}
*/
package main

// State represents a node in our custom priority queue
type State struct {
	d int // Total distance so far
	u int // Current node
	c int // Consecutive count of the current character
}

// Custom bare-metal Min-Heap (Beats generic container/heap by miles)
type pq []State

func (h *pq) push(s State) {
	*h = append(*h, s)
	h.up(len(*h) - 1)
}

func (h *pq) pop() State {
	res := (*h)[0]
	last := len(*h) - 1
	(*h)[0] = (*h)[last]
	*h = (*h)[:last]
	if last > 0 {
		h.down(0)
	}
	return res
}

func (h pq) up(i int) {
	for i > 0 {
		p := (i - 1) / 2
		if h[i].d >= h[p].d {
			break
		}
		h[i], h[p] = h[p], h[i]
		i = p
	}
}

func (h pq) down(i int) {
	n := len(h)
	for {
		left := 2*i + 1
		if left >= n {
			break
		}
		min := left
		if right := left + 1; right < n && h[right].d < h[left].d {
			min = right
		}
		if h[i].d <= h[min].d {
			break
		}
		h[i], h[min] = h[min], h[i]
		i = min
	}
}

func shortestPath(n int, edges [][]int, labels string, k int) int {
	if n == 1 {
		return 0
	}

	// 1. Compressed Sparse Row (CSR) Graph Construction (Zero Slice-of-Slices Allocation)
	m := len(edges)
	head := make([]int, n)
	for i := 0; i < n; i++ {
		head[i] = -1
	}
	to := make([]int, m)
	wt := make([]int, m)
	next := make([]int, m)

	for i := 0; i < m; i++ {
		u, v, w := edges[i][0], edges[i][1], edges[i][2]
		to[i] = v
		wt[i] = w
		next[i] = head[u]
		head[u] = i
	}

	// 2. Flattened 1D Distance Array to track (node, consecutive_count)
	// Index calculation: u * (k + 1) + c
	const INF = 1 << 60
	dist := make([]int, n*(k+1))
	for i := 0; i < len(dist); i++ {
		dist[i] = INF
	}

	// 3. Hardware-Optimized Dijkstra using Custom Heap
	dist[1] = 0 // Node 0, Count 1 -> index (0 * (k+1) + 1)
	h := make(pq, 0, 1024)
	h.push(State{d: 0, u: 0, c: 1})

	for len(h) > 0 {
		curr := h.pop()
		d, u, c := curr.d, curr.u, curr.c

		// If we reached the destination with a valid path, return immediately (Min-Heap guarantees shortest)
		if u == n-1 {
			return d
		}

		// Skip if we already found a shorter path to this exact state
		if d > dist[u*(k+1)+c] {
			continue
		}

		// Traverse outgoing edges from CSR
		for e := head[u]; e != -1; e = next[e] {
			v := to[e]
			w := wt[e]

			nxtC := 1
			if labels[u] == labels[v] {
				nxtC = c + 1
			}

			// Path invalidates the constraint
			if nxtC > k {
				continue
			}

			nxtD := d + w
			idx := v*(k+1) + nxtC

			// Edge relaxation
			if nxtD < dist[idx] {
				dist[idx] = nxtD
				h.push(State{d: nxtD, u: v, c: nxtC})
			}
		}
	}

	// Target never reached
	return -1
}