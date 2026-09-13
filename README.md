# leetcode-stack
---
> **A zero-to-one algorithmic infrastructure, independently architected for state-space optimization, advanced data structure engineering, and computational efficiency.**

Engineered entirely from the ground up, this repository serves as a systematic archive of rigorous problem-solving. Every algorithmic module is strictly authored to enforce minimal auxiliary space and optimal asymptotic time complexities, reflecting continuous deployment from the LeetCode platform.

---

## The Execution Stack

Solutions are architected via a tri-lingual stack, strategically chosen for specific computational paradigms:

* **`C++`** &mdash; Granular memory management, pointer arithmetic, and low-latency execution.
* **`Python 3`** &mdash; Rapid logic orchestration, advanced built-in data structures, and mathematical modeling.
* **`JavaScript / Node.js`** &mdash; Asynchronous execution patterns and web-standard logic deployment.

---

## Architecture & Taxonomy

The repository is maintained autonomously and structured strictly by algorithmic taxonomy. Each isolated module contains:
* The raw source code implementation.
* Standardized JSON metadata indicating the `problem_name`, `category`, `time_complexity`, and `space_complexity`.

### Snippets

**Arrays &mdash; State-Space Grouping:**
```python
from Arrays.lexicographically_smallest_array import lexicographically_smallest_array

nums = [1, 5, 3, 9, 8]
print(lexicographically_smallest_array(nums, 2))
# Output: [1, 3, 5, 8, 9]
```

**Hashing &mdash; O(1) Probabilistic Lookups:**
```python
from Hashing.two_sum import Solution

sol = Solution()
nums = [2, 7, 11, 15]
print(sol.twoSum(nums, 9))
# Output: [0, 1]
```

**Cyclic Sort &mdash; First Missing Positive:**
```javascript
// From Cyclic_Sort/first_missing_positive.js
const { firstMissingPositive } = require('./Cyclic_Sort/first_missing_positive');

const nums = [3, 4, -1, 1];
console.log(firstMissingPositive(nums));
# Output: 2
```

**Graphs — Bitmask Shortest Path Cleanup:**
```cpp
// From Graphs/shortest_path_cleanup_bitmask.cpp
#include "Graphs/shortest_path_cleanup_bitmask.cpp"

Solution sol;
std::vector<std::string> classroom = {"S..L", "X...", "...X"};
std::cout << sol.minMoves(classroom, 5) << std::endl;
```

**Trees — Recursive Subtree State Aggregation:**
```python
from Trees.subtree_average import Solution, TreeNode

root = TreeNode(4)
root.left = TreeNode(8)
root.right = TreeNode(5)
root.left.left = TreeNode(0)
root.left.right = TreeNode(1)
root.right.right = TreeNode(6)

print(Solution().averageOfSubtree(root))
# Output: 5
```

---

## Engineering Standards

All modules are engineered with a strict focus on system-level constraints:
* **Time Complexity:** Optimized for minimal asymptotic upper bounds.
* **Space Complexity:** Emphasis on strictly in-place modifications and zero-overhead auxiliary space allocation.
* **Taxonomy:** Arrays, Linked Lists, Two Pointers, Trees, Graphs, Dynamic Programming, and Advanced Heuristics.

---

## Automation Pipeline

This infrastructure relies on zero manual indexing. Solutions are integrated, compiled, and tested via a fully automated pipeline backed by GitHub Actions CI.

### Local Execution & CI Commands

To execute the automation lifecycle locally, deploy the standard Makefile protocols:

**Validate Metadata & Structure:**
```bash
make validate
```
_Automatically discovers taxonomy directories and detects broken structure, naming violations, and invalid metadata._

**Execute Testing Framework:**
```bash
make test
```
_Dynamically runs unified language-agnostic tests in `tests/` across C++, Python, and Node.js._

**Reproducible Benchmarking:**
```bash
make benchmark
```
_Captures execution times, memory usage, and commit SHA inside `benchmarks/results.json`._

**Generate Repository Index:**
```bash
make index
```
_Parses metadata in code files and constructs `index/README.md`._

---

## Fault Tolerance

These modules are architected as isolated algorithmic functions stripped of redundant boilerplate. Local execution may encounter expected integration faults. Deploy the following protocols to override them:

* **Missing Entry Point:** Core C++ modules omit driver code (e.g. `main()`). Ensure you instantiate the `Solution` class inside a standard test driver (as done in `tests/`).
* **V8 Module Resolution:** If JavaScript modules encounter scope faults, use standard Node.js module loading or `eval()` via test drivers.

---

<br>
<div align="right">
  <b>Rudranarayan Jena</b><br>
  <i>Founder @ Voxion Labs</i>
</div>
