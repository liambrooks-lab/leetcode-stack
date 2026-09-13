/*
{
  "problem_name": "Longest Repeat Substr",
  "category": "Segment_Tree",
  "time_complexity": "O(N)",
  "space_complexity": "O(1)"
}
*/
/**
 * @param {string} s
 * @param {string} queryCharacters
 * @param {number[]} queryIndices
 * @return {number[]}
 */
var longestRepeating = function(s, queryCharacters, queryIndices) {
    const n = s.length;
    const arr = s.split('');
    // segment tree node: [pre, suf, max, leftChar, rightChar, len]
    const pre = new Int32Array(4 * n), suf = new Int32Array(4 * n), mx = new Int32Array(4 * n);
    const lc = new Int8Array(4 * n), rc = new Int8Array(4 * n), len = new Int32Array(4 * n);
    const merge = (node) => {
        const l = 2 * node, r = 2 * node + 1;
        lc[node] = lc[l]; rc[node] = rc[r]; len[node] = len[l] + len[r];
        pre[node] = pre[l]; if (pre[l] === len[l] && rc[l] === lc[r]) pre[node] = len[l] + pre[r];
        suf[node] = suf[r]; if (suf[r] === len[r] && rc[l] === lc[r]) suf[node] = len[r] + suf[l];
        mx[node] = Math.max(mx[l], mx[r]);
        if (rc[l] === lc[r]) mx[node] = Math.max(mx[node], suf[l] + pre[r]);
    };
    const build = (node, l, r) => {
        if (l === r) { pre[node] = suf[node] = mx[node] = 1; lc[node] = rc[node] = arr[l].charCodeAt(0) - 97; len[node] = 1; return; }
        const mid = (l + r) >> 1;
        build(2 * node, l, mid); build(2 * node + 1, mid + 1, r); merge(node);
    };
    const update = (node, l, r, pos, ch) => {
        if (l === r) { lc[node] = rc[node] = ch; return; }
        const mid = (l + r) >> 1;
        if (pos <= mid) update(2 * node, l, mid, pos, ch); else update(2 * node + 1, mid + 1, r, pos, ch);
        merge(node);
    };
    build(1, 0, n - 1);
    const res = [];
    for (let q = 0; q < queryIndices.length; q++) {
        update(1, 0, n - 1, queryIndices[q], queryCharacters.charCodeAt(q) - 97);
        res.push(mx[1]);
    }
    return res;
};