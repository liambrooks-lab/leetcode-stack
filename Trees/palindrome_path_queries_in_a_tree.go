/*
{
    "problem_name": "Minimum XOR Path in a Grid",
    "category": "Dynamic Programming / Bit Manipulation",
    "time_complexity": "O(m * n * 1024) -> Fully unrolled contiguous memory traversal evaluating all state sets natively.",
    "space_complexity": "O(n * 1024) -> Strictly stack-allocated C-style arrays. Zero heap allocations. L1/L2 cache optimized."
}
*/


var adj, deg, sizes, heavy, chain, queue [50_000]uint16
var bit, masks [50_001]uint32

func palindromePath(n int, edges [][]int, s string, queries []string) []bool {
	sentinel := uint16(n)
	clear(adj[:n])
	clear(deg[:n])
	deg[0] = 2

	for _, edge := range edges {
		u, v := uint16(edge[0]), uint16(edge[1])
		adj[u] ^= v
		adj[v] ^= u
		deg[u]++
		deg[v]++
	}
	q := 0

	for u := range uint16(n) {
		sizes[u] = 1
		heavy[u] = sentinel
		if deg[u] == 1 {
			queue[q] = u
			q++
		}
	}

	for i := 0; i < q; i++ {
		u := queue[i]
		v := adj[u]
		size := sizes[u]
		sizes[v] += size
		if child := heavy[v]; child == sentinel || size > sizes[child] {
			heavy[v] = u
		}
		adj[v] ^= u
		deg[v]--
		if deg[v] == 1 {
			queue[q] = v
			q++
		}
	}

	queue[q] = 0
	q++
	idxs := deg[:n]
	clear(idxs)

	var pos uint16
	for i := q - 1; i >= 0; i-- {
		u := queue[i]
		if idxs[u] != 0 {
			continue
		}
		i := u
		for u != sentinel {
			pos++
			chain[u] = i
			idxs[u] = pos
			masks[pos] = 1 << (s[u] - 'a')
			u = heavy[u]
		}
	}

	copy(bit[:n+1], masks[:n+1])

	for i := 1; i <= n; i++ {
		if j := i + (i & -i); j <= n {
			bit[j] ^= bit[i]
		}
	}

	result := make([]bool, 0, len(queries))

	for _, query := range queries {
		update := query[0] == 'u'
		ptr := 6
		if update {
			ptr = 7
		}

		var u uint16
		for ; query[ptr] != ' '; ptr++ {
			u = u*10 + uint16(query[ptr]-'0')
		}
		ptr++

		if update {
			mask := uint32(1) << (query[ptr] - 'a')
			pos := int(idxs[u])
			delta := mask ^ masks[pos]
			if delta != 0 {
				masks[pos] = mask
				for i := pos; i <= n; i += i & -i {
					bit[i] ^= delta
				}
			}
			continue
		}

		var v uint16
		for ; ptr < len(query); ptr++ {
			v = v*10 + uint16(query[ptr]-'0')
		}

		var path uint32
		for chain[u] != chain[v] {
			if idxs[chain[u]] < idxs[chain[v]] {
				u, v = v, u
			}
			for right := idxs[u]; right > 0; right &= right - 1 {
				path ^= bit[right]
			}
			for left := idxs[chain[u]] - 1; left > 0; left &= left - 1 {
				path ^= bit[left]
			}
			u = adj[chain[u]]
		}

		if idxs[u] > idxs[v] {
			u, v = v, u
		}
		for right := idxs[v]; right > 0; right &= right - 1 {
			path ^= bit[right]
		}
		for left := idxs[u] - 1; left > 0; left &= left - 1 {
			path ^= bit[left]
		}

		result = append(result, path&(path-1) == 0)
	}

	return result
}