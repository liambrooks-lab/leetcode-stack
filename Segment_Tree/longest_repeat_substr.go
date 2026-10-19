/*
{
  "problem_name": "Longest Repeat Substr",
  "category": "Segment_Tree",
  "time_complexity": "O(N)",
  "space_complexity": "O(1)"
}
*/

package segmenttree

// LongestRepeating computes the length of the longest substring with repeated characters after each query.
func LongestRepeating(s string, queryCharacters string, queryIndices []int) []int {
	n := len(s)
	if n == 0 {
		return []int{}
	}

	size := 4 * n
	pre := make([]int32, size)
	suf := make([]int32, size)
	mx := make([]int32, size)
	lenNode := make([]int32, size)
	lc := make([]int8, size)
	rc := make([]int8, size)

	merge := func(node int) {
		l := 2 * node
		r := 2*node + 1
		lc[node] = lc[l]
		rc[node] = rc[r]
		lenNode[node] = lenNode[l] + lenNode[r]

		pre[node] = pre[l]
		if pre[l] == lenNode[l] && rc[l] == lc[r] {
			pre[node] = lenNode[l] + pre[r]
		}

		suf[node] = suf[r]
		if suf[r] == lenNode[r] && rc[l] == lc[r] {
			suf[node] = lenNode[r] + suf[l]
		}

		maxVal := mx[l]
		if mx[r] > maxVal {
			maxVal = mx[r]
		}
		if rc[l] == lc[r] {
			span := suf[l] + pre[r]
			if span > maxVal {
				maxVal = span
			}
		}
		mx[node] = maxVal
	}

	var build func(node, l, r int)
	build = func(node, l, r int) {
		if l == r {
			pre[node] = 1
			suf[node] = 1
			mx[node] = 1
			lenNode[node] = 1
			charVal := int8(s[l] - 'a')
			lc[node] = charVal
			rc[node] = charVal
			return
		}
		mid := (l + r) >> 1
		build(2*node, l, mid)
		build(2*node+1, mid+1, r)
		merge(node)
	}

	var update func(node, l, r, pos int, ch int8)
	update = func(node, l, r, pos int, ch int8) {
		if l == r {
			lc[node] = ch
			rc[node] = ch
			return
		}
		mid := (l + r) >> 1
		if pos <= mid {
			update(2*node, l, mid, pos, ch)
		} else {
			update(2*node+1, mid+1, r, pos, ch)
		}
		merge(node)
	}

	build(1, 0, n-1)

	qLen := len(queryIndices)
	res := make([]int, qLen)
	for q := 0; q < qLen; q++ {
		update(1, 0, n-1, queryIndices[q], int8(queryCharacters[q]-'a'))
		res[q] = int(mx[1])
	}

	return res
}

func longestRepeating(s string, queryCharacters string, queryIndices []int) []int {
	return LongestRepeating(s, queryCharacters, queryIndices)
}
