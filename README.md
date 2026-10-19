# leetcode-stack
 
[![Read in English](https://img.shields.io/badge/%F0%9F%8C%90_Read_in_English-1081c1?style=for-the-badge)](https://github.com/liambrooks-lab/leetcode-stack/blob/main/README.md)
 
---
> **एक शून्य-से-शिखर (0-to-1) तक की कलन विधि (algorithmic) अवसंरचना, जिसे अवस्था-समष्टि अनुकूलन (state-space optimization), उन्नत आँकड़ा संरचना अभियांत्रिकी (advanced data structure engineering) और संगणनात्मक दक्षता (computational efficiency) के लिए स्वतंत्र रूप से निर्मित किया गया है।**
 
पूर्णतः आधारभूत स्तर (ground up) से निर्मित यह संग्रह (repository) कठोर समस्या-समाधान का एक व्यवस्थित अभिलेखागार (archive) है। प्रत्येक कलन विधि मॉड्यूल को न्यूनतम सहायक स्थान (auxiliary space) और इष्टतम अनंतस्पर्शी समय जटिलता (optimal asymptotic time complexity) सुनिश्चित करने के लिए कड़ाई से लिखा गया है, जो लीटकोड (LeetCode) मंच से निरंतर परिनियोजन (deployment) को दर्शाता है।
 
---
 
## निष्पादन प्रौद्योगिकी (Execution Stack)
 
समाधानों को तीन रनटाइम परिवेशों में, उनकी वास्तुकलात्मक विशेषताओं के आधार पर, लागू किया गया है:
 
* **`C++`** (C++17) &mdash; प्रत्यक्ष स्मृति नियंत्रण (direct memory control), सूचक अंकगणित (pointer arithmetic), और नियतात्मक (deterministic) निष्पादन प्रदर्शन।
* **`Python 3`** &mdash; मानक लाइब्रेरी की आँकड़ा संरचनाएँ, संक्षिप्त कलन विधि संयोजन, और गणितीय प्रतिरूपण।
* **`Golang`** (Go 1.22) &mdash; स्थैतिक टाइपिंग (static typing), स्पष्ट स्मृति आवंटन, कचरा संग्रहण (garbage collection) के बोझ को घटाने के लिए पूर्व-आवंटित स्लाइस (pre-allocated slices), और नेटिव परीक्षण टूलिंग।
---
 
## वास्तुकला और वर्गीकरण (Architecture & Taxonomy)
 
यह संग्रह स्वायत्त रूप से प्रबंधित है और कलन विधि वर्गीकरण के आधार पर कड़ाई से संरचित है। प्रत्येक पृथक मॉड्यूल में आमतौर पर शामिल हैं:
* मूल स्रोत कूट (source code) कार्यान्वयन।
* समस्या की सीमाएँ (constraints) और सीमांत-स्थिति (edge-case) परिभाषाएँ।
* निष्पादन मापदंड (समय और स्थान जटिलता, वास्तविक समय में समकालिक)।
### कोड के अंश (Snippets)
 
**व्यूह (Arrays) &mdash; यथास्थान दो-सूचक विभाजन (In-Place Two-Pointer Partitioning):**
```go
// Partitions slice in-place around a predicate in O(N) time and O(1) auxiliary space
func partition(nums []int, pivot int) int {
	left := 0
	for right := 0; right < len(nums); right++ {
		if nums[right] < pivot {
			nums[left], nums[right] = nums[right], nums[left]
			left++
		}
	}
	return left
}
```
 
**पश्चमार्ग-अनुसरण (Backtracking) &mdash; अवस्था-समष्टि खोज और शाखा छँटाई (Branch Pruning):**
```python
# Generic backtracking engine with state pruning
def backtrack(candidates: list[int], target: int) -> list[list[int]]:
    result = []
    candidates.sort()
 
    def dfs(start: int, remaining: int, path: list[int]):
        if remaining == 0:
            result.append(list(path))
            return
        for i in range(start, len(candidates)):
            if candidates[i] > remaining:
                break
            if i > start and candidates[i] == candidates[i - 1]:
                continue
            path.append(candidates[i])
            dfs(i + 1, remaining - candidates[i], path)
            path.pop()
 
    dfs(0, target, [])
    return result
```
 
**द्विआधारी खोज (Binary Search) &mdash; एकदिष्ट विधेय निम्न सीमा (Monotonic Predicate Lower Bound):**
```cpp
// Returns the first index where predicate is satisfied; O(log N) time, O(1) space
int lower_bound(const std::vector<int>& nums, int target) {
    int left = 0, right = static_cast<int>(nums.size());
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] >= target) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}
```
 
**द्विआधारी अनुक्रमित वृक्ष (Binary Indexed Tree / Fenwick Tree) &mdash; उपसर्ग संचय और बिंदु परिवर्तन:**
```cpp
// O(log N) point update and prefix query on 1-based indexing
class FenwickTree {
    std::vector<int> tree;
    int size;
public:
    explicit FenwickTree(int n) : size(n), tree(n + 1, 0) {}
 
    void add(int i, int delta) {
        for (; i <= size; i += i & -i) tree[i] += delta;
    }
 
    int query(int i) const {
        int sum = 0;
        for (; i > 0; i -= i & -i) sum += tree[i];
        return sum;
    }
};
```
 
**बिट हेरफेर (Bit Manipulation) &mdash; मास्क संक्रियाएँ और निम्नतम सेट बिट:**
```go
// Pure bitwise operations bypassing arithmetic overhead; O(1) time and space
func bitwiseOperations(n int, mask int) (lowestBit int, isPowerOfTwo bool, clearedBit int) {
	lowestBit = n & -n                      // Isolate lowest set bit
	isPowerOfTwo = n > 0 && (n&(n-1)) == 0 // Check power of two
	clearedBit = n & ^(1 << mask)          // Clear specific bit at mask position
	return
}
```
 
**चक्रीय छँटाई (Cyclic Sort) &mdash; यथास्थान 1-से-N सूचकांक मानचित्रण:**
```python
# Aligns positive integers to their 0-indexed positions in O(N) time and O(1) space
def cyclic_sort(nums: list[int]) -> list[int]:
    i, n = 0, len(nums)
    while i < n:
        correct_idx = nums[i] - 1
        if 0 <= correct_idx < n and nums[i] != nums[correct_idx]:
            nums[i], nums[correct_idx] = nums[correct_idx], nums[i]
        else:
            i += 1
    return nums
```
 
**गतिशील क्रमादेशन (Dynamic Programming) &mdash; स्थान-अनुकूलित रोलिंग अवस्था सारणीकरण:**
```go
// Computes recurrence using rolling buffer; O(N) time and O(1) auxiliary space
func rollingDP(cost []int) int {
	n := len(cost)
	if n <= 1 {
		return 0
	}
	prev2, prev1 := 0, 0
	for i := 2; i <= n; i++ {
		c1 := prev1 + cost[i-1]
		c2 := prev2 + cost[i-2]
		current := c1
		if c2 < current {
			current = c2
		}
		prev2, prev1 = prev1, current
	}
	return prev1
}
```
 
**खेल सिद्धांत (Game Theory) &mdash; मिनिमैक्स टर्मिनल अवस्था मूल्यांकन:**
```python
# Evaluates symmetric zero-sum terminal conditions in O(N) time and O(1) space
def evaluate_game(state: list[int]) -> bool:
    balance = sum(state[:len(state)//2]) - sum(state[len(state)//2:])
    return balance != 0
```
 
**आलेख (Graphs) &mdash; चौड़ाई-प्रथम खोज (BFS) और स्तर-क्रम ट्रैवर्सल:**
```cpp
// Traverses unweighted graph via BFS; O(V + E) time, O(V) space
std::vector<int> bfs_traversal(int start, const std::vector<std::vector<int>>& adj) {
    std::vector<int> order;
    std::vector<bool> visited(adj.size(), false);
    std::queue<int> q;
 
    visited[start] = true;
    q.push(start);
 
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);
 
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    return order;
}
```
 
**लालची दृष्टिकोण (Greedy) &mdash; एकदिष्ट सीमांत विस्तार (Monotonic Frontier Expansion):**
```python
# Expands furthest reachable frontier in a single linear pass; O(N) time, O(1) space
def greedy_jump_frontier(nums: list[int]) -> int:
    jumps = current_end = furthest = 0
    for i in range(len(nums) - 1):
        furthest = max(furthest, i + nums[i])
        if i == current_end:
            jumps += 1
            current_end = furthest
    return jumps
```
 
**हैशिंग (Hashing) &mdash; स्थिर-समय अवस्था विलोपन (Deduplication) और आवृत्ति ट्रैकिंग:**
```python
# Single-pass frequency mapping for target resolution; O(N) time, O(N) space
def find_pair_sum(nums: list[int], target: int) -> list[int]:
    lookup = {}
    for i, x in enumerate(nums):
        complement = target - x
        if complement in lookup:
            return [lookup[complement], i]
        lookup[x] = i
    return []
```
 
**अंतराल (Intervals) &mdash; यथास्थान सीमा स्वीप और विलय:**
```python
# Merges overlapping intervals after O(N log N) sort; O(N) space
def merge_intervals(intervals: list[list[int]]) -> list[list[int]]:
    if not intervals:
        return []
    intervals.sort(key=lambda x: x[0])
    merged = [intervals[0]]
    for start, end in intervals[1:]:
        if start <= merged[-1][1]:
            merged[-1][1] = max(merged[-1][1], end)
        else:
            merged.append([start, end])
    return merged
```
 
**श्रृंखलाबद्ध सूचियाँ (Linked Lists) &mdash; तेज़ और धीमा सूचक द्वारा चक्र पहचान:**
```go
// Detects cycle existence via Floyd's tortoise and hare; O(N) time, O(1) space
func hasCycle(head *ListNode) bool {
	slow, fast := head, head
	for fast != nil && fast.Next != nil {
		slow = slow.Next
		fast = fast.Next.Next
		if slow == fast {
			return true
		}
	}
	return false
}
```
 
**गणित (Math) &mdash; मॉड्यूलो के साथ द्विआधारी घातांक (Binary Exponentiation):**
```cpp
// Computes (base^exp) % mod in O(log exp) time and O(1) space
long long modular_pow(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}
```
 
**आव्यूह (Matrices) &mdash; दिशात्मक सीमा संकुचन स्कैन:**
```python
# Traverses a 2D matrix in spiral boundary order; O(M * N) time, O(1) auxiliary space
def matrix_boundary_scan(matrix: list[list[int]]) -> list[int]:
    if not matrix or not matrix[0]:
        return []
    top, bottom = 0, len(matrix) - 1
    left, right = 0, len(matrix[0]) - 1
    result = []
 
    while top <= bottom and left <= right:
        for c in range(left, right + 1):
            result.append(matrix[top][c])
        top += 1
        for r in range(top, bottom + 1):
            result.append(matrix[r][right])
        right -= 1
        if top <= bottom:
            for c in range(right, left - 1, -1):
                result.append(matrix[bottom][c])
            bottom -= 1
        if left <= right:
            for r in range(bottom, top - 1, -1):
                result.append(matrix[r][left])
            left += 1
 
    return result
```
 
**उपसर्ग योग (Prefix Sum) &mdash; O(1) क्वेरी के लिए सहायक परास संचय:**
```go
// Pre-allocates prefix sum array for O(1) range sum queries; O(N) time and space
func buildPrefixSum(nums []int) []int {
	n := len(nums)
	prefix := make([]int, n+1)
	for i := 0; i < n; i++ {
		prefix[i+1] = prefix[i] + nums[i]
	}
	return prefix // Range [i, j] sum is prefix[j+1] - prefix[i]
}
```
 
**खंड वृक्ष (Segment Tree) &mdash; बिंदु अद्यतन और परास समुच्चयन (Range Aggregation):**
```cpp
// Range sum segment tree; O(N) construction, O(log N) query and update
class SegmentTree {
    std::vector<int> tree;
    int n;
public:
    explicit SegmentTree(const std::vector<int>& data) : n(data.size()), tree(4 * data.size(), 0) {
        build(data, 1, 0, n - 1);
    }
 
    void build(const std::vector<int>& data, int node, int l, int r) {
        if (l == r) { tree[node] = data[l]; return; }
        int mid = (l + r) / 2;
        build(data, 2 * node, l, mid);
        build(data, 2 * node + 1, mid + 1, r);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
 
    void update(int node, int l, int r, int idx, int val) {
        if (l == r) { tree[node] = val; return; }
        int mid = (l + r) / 2;
        if (idx <= mid) update(2 * node, l, mid, idx, val);
        else update(2 * node + 1, mid + 1, r, idx, val);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
 
    int query(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return tree[node];
        if (r < ql || l > qr) return 0;
        int mid = (l + r) / 2;
        return query(2 * node, l, mid, ql, qr) + query(2 * node + 1, mid + 1, r, ql, qr);
    }
};
```
 
**खिसकती खिड़की (Sliding Window) &mdash; गतिशील दो-सूचक संकुचन:**
```go
// Maintains variable-size sliding window with frequency bounds; O(N) time, O(K) space
func longestDistinctSubstr(s string) int {
	lastPos := make(map[byte]int)
	maxLen, left := 0, 0
	for right := 0; right < len(s); right++ {
		if prev, exists := lastPos[s[right]]; exists && prev >= left {
			left = prev + 1
		}
		lastPos[s[right]] = right
		curLen := right - left + 1
		if curLen > maxLen {
			maxLen = curLen
		}
	}
	return maxLen
}
```
 
**छँटाई (Sorting) &mdash; त्रि-मार्गी यथास्थान डच नेशनल फ्लैग विभाजन:**
```cpp
// Partitions array into three regions (0, 1, 2) in-place; O(N) time, O(1) space
void three_way_partition(std::vector<int>& nums) {
    int low = 0, mid = 0, high = static_cast<int>(nums.size()) - 1;
    while (mid <= high) {
        if (nums[mid] == 0) {
            std::swap(nums[low++], nums[mid++]);
        } else if (nums[mid] == 1) {
            mid++;
        } else {
            std::swap(nums[mid], nums[high--]);
        }
    }
}
```
 
**ढेर (Stacks) &mdash; एकदिष्ट अगला-बड़ा-तत्व (Next-Greater Element) समाधान:**
```go
// Finds next greater element index for each position; O(N) time, O(N) space
func nextGreaterIndices(nums []int) []int {
	n := len(nums)
	res := make([]int, n)
	for i := range res {
		res[i] = -1
	}
	stack := make([]int, 0, n) // Monotonic decreasing index stack
 
	for i := 0; i < n; i++ {
		for len(stack) > 0 && nums[i] > nums[stack[len(stack)-1]] {
			top := stack[len(stack)-1]
			stack = stack[:len(stack)-1]
			res[top] = i
		}
		stack = append(stack, i)
	}
	return res
}
```
 
**सूत्र (Strings) &mdash; दो-सूचक पैलिंड्रोम सीमा विस्तार:**
```python
# Expands around centers in-place; O(N^2) time, O(1) auxiliary space
def longest_palindrome_span(s: str) -> str:
    start, max_len = 0, 0
    for i in range(len(s)):
        for l, r in ((i, i), (i, i + 1)):
            while l >= 0 and r < len(s) and s[l] == s[r]:
                l -= 1
                r += 1
            span = r - l - 1
            if span > max_len:
                max_len = span
                start = l + 1
    return s[start:start + max_len]
```
 
**वृक्ष (Trees) &mdash; पोस्ट-ऑर्डर उप-वृक्ष समुच्चयन और अवस्था प्रसार:**
```python
# Traverses binary tree in post-order aggregating subtree metrics; O(N) time, O(H) space
def evaluate_subtree_metrics(root) -> tuple[int, int]:
    if not root:
        return 0, 0 # (sum, count)
    left_sum, left_count = evaluate_subtree_metrics(root.left)
    right_sum, right_count = evaluate_subtree_metrics(root.right)
    total_sum = root.val + left_sum + right_sum
    total_count = 1 + left_count + right_count
    return total_sum, total_count
```
 
**दो सूचक (Two Pointers) &mdash; अनावश्यक सीमा छँटाई के साथ अंदर की ओर अभिसरण:**
```go
// Inward two-pointer search with redundant boundary skipping; O(N) time, O(1) space
func maxAreaContainer(height []int) int {
	left, right := 0, len(height)-1
	maxArea := 0
	for left < right {
		hL, hR := height[left], height[right]
		h := hL
		if hR < h {
			h = hR
		}
		area := h * (right - left)
		if area > maxArea {
			maxArea = area
		}
		if hL < hR {
			for left < right && height[left] <= hL {
				left++
			}
		} else {
			for left < right && height[right] <= hR {
				right--
			}
		}
	}
	return maxArea
}
```
 
---
 
## अभियांत्रिकी मानक (Engineering Standards)
 
सभी मॉड्यूल्स को प्रणाली-स्तरीय (system-level) सीमाओं पर सख्त ध्यान केंद्रित करते हुए निर्मित किया गया है:
* **समय जटिलता (Time Complexity):** न्यूनतम अनंतस्पर्शी ऊपरी सीमा के लिए अनुकूलित।
* **स्थान जटिलता (Space Complexity):** पूर्णतः यथास्थान (in-place) संशोधनों और शून्य-अतिरिक्त सहायक स्थान आवंटन पर ज़ोर।
* **वर्गीकरण (Taxonomy):** सरणियाँ (Arrays), पश्चमार्ग-अनुसरण (Backtracking), द्विआधारी खोज (Binary Search), बिट हेरफेर (Bit Manipulation), चक्रीय छँटाई (Cyclic Sort), गतिशील क्रमादेशन (Dynamic Programming), खेल सिद्धांत (Game Theory), आलेख (Graphs), लालची दृष्टिकोण (Greedy), हैशिंग (Hashing), अंतराल (Intervals), श्रृंखलाबद्ध सूचियाँ (Linked Lists), गणित (Math), आव्यूह (Matrices), उपसर्ग योग (Prefix Sum), खंड वृक्ष (Segment Tree), खिसकती खिड़की (Sliding Window), ढेर (Stacks), सूत्र (Strings), वृक्ष (Trees), और दो सूचक (Two Pointers) में व्यापक कवरेज।
---
 
## स्वचालन पाइपलाइन (Automation Pipeline)
 
यह अवसंरचना शून्य हस्तचालित अनुक्रमण (manual indexing) पर निर्भर करती है। स्वचालित CI/CD समकालन कार्यप्रवाह (workflows) के माध्यम से मुख्य मंच पर सफल सीमा सत्यापन के बाद समाधानों को वास्तविक समय में एकीकृत, संकलित और अद्यतित किया जाता है। हमारा अनुकूलित परीक्षण, लिंटिंग, और बेयर-मेटल बेंचमार्किंग ढांचा गिटहब एक्शंस (GitHub Actions) के ज़रिए त्रुटिहीन (flawlessly) रूप से कार्य करता है।
 
---
 
## संगणनात्मक प्रतिमान और सूक्ष्म-अनुकूलन (Computational Paradigms & Micro-Optimizations)
 
मानक अनंतस्पर्शी सीमाओं का पालन करने के अतिरिक्त, यह संग्रह रनटाइम ओवरहेड (जैसे रनटाइम कचरा संग्रहण का बोझ और हीप आवंटन विलंबता) को न्यूनतम करने के लिए सख्त निष्पादन बाधाएँ लागू करता है:
 
* **अवस्था-समष्टि छँटाई (State-Space Pruning):** निष्पादन से पूर्व ही अवांछित पुनरावर्ती शाखाओं और अतिव्यापी उप-समस्याओं का गणितीय समापन।
* **यथास्थान परिवर्तनशीलता (In-Place Mutability):** सूचक हेरफेर (pointer manipulation), चक्रीय अदला-बदली और बिटवाइज़ अवस्था खिसकाव के ज़रिए सहायक ट्रैकिंग संरचनाओं का न्यूनीकरण।
* **रनटाइम-अज्ञेय अंकगणित (Runtime-Agnostic Arithmetic):** टाइप-रूपांतरण (type-conversion) विलंबता से बचने के लिए सीधे ASCII स्मृति पहुँच और बिट-स्तरीय संक्रियाओं का उपयोग।
---
 
## स्थानीय निष्पादन (Local Execution)
 
कार्यान्वयन को स्थानीय स्तर पर जांचने के लिए, निम्नलिखित मानक निष्पादन प्रोटोकॉल लागू करें:
 
**C++**
```bash
g++ -O3 -std=c++17 filename.cpp -o executable
./executable
```
 
**Python**
```bash
python3 filename.py
```
 
**Golang**
```bash
go run filename.go
```
 
---
 
## त्रुटि सहिष्णुता (Fault Tolerance)
 
इन मॉड्यूलों को निरर्थक बॉयलरप्लेट (boilerplate) से मुक्त, पृथक कलन विधि कार्यों के रूप में संरचित किया गया है। स्थानीय निष्पादन में अपेक्षित एकीकरण त्रुटियाँ आ सकती हैं। उन्हें अधिरोहित (override) करने के लिए निम्नलिखित प्रोटोकॉल लागू करें:
 
* **अनुपस्थित प्रवेश बिंदु (Missing Entry Point / Execution Halt):** मुख्य मॉड्यूलों में चालक (driver) कोड नहीं होता है। आपको स्थानीय C++ संकलन से पूर्व एक मानक `main()` फ़ंक्शन के भीतर मैन्युअली `Solution` क्लास को आरंभीकृत (instantiate) करना होगा।
* **स्मृति विसंगतियाँ और सेगमेंटेशन फ़ॉल्ट (Memory Anomalies & Segmentation Faults):** अनारंभीकृत सूचकों, सीमा-से-बाहर पहुँच, या स्टैक स्मैशिंग का निदान करने के लिए, स्थानीय परीक्षण के दौरान GCC स्मृति स्वच्छता (memory sanitization) लागू करें:
```bash
  g++ -O3 -Wall -Wextra -fsanitize=address filename.cpp -o debug_exec
  ./debug_exec
```
* **पैकेज मेन और प्रवेश बिंदु (Package Main & Entry Point):** मुख्य मॉड्यूल कार्यात्मक पैकेजों में संगठित हैं और उनमें `main` चालक फ़ंक्शन नहीं हैं। `go run` से पृथक निष्पादन के लिए एक `main` पैकेज और प्रवेश बिंदु परिभाषित करें, या `go test -v` से परीक्षण चलाएँ।
---
 
<br>
<div align="right">
  <b>Rudranarayan Jena</b><br>
  <i>Founder @ Voxion Labs</i>
</div>
---
<div align="center">
  (c) 2026 Rudranarayan Jena
</div>
<p align="center">
 Leetcode · DSA · Python3 · C++ · Golang
</p>
 
