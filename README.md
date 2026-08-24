# leetcode-stack
---
> **A zero-to-one algorithmic infrastructure, independently architected for state-space optimization, advanced data structure engineering, and computational efficiency..**

Engineered entirely from the ground up, this repository serves as a systematic archive of rigorous problem-solving. Every algorithmic module is strictly authored to enforce minimal auxiliary space and optimal asymptotic time complexities, reflecting continuous deployment from the LeetCode platform.

---

## The Execution Stack

Solutions are architected via a tri-lingual stack, strategically chosen for specific computational paradigms:

* **`C++`** &mdash; Granular memory management, pointer arithmetic, and low-latency execution.
* **`Python 3`** &mdash; Rapid logic orchestration, advanced built-in data structures, and mathematical modeling.
* **`JavaScript / Node.js`** &mdash; Asynchronous execution patterns and web-standard logic deployment.

---

## Architecture & Taxonomy

The repository is maintained autonomously and structured strictly by algorithmic taxonomy. Each isolated module typically contains:
* The raw source code implementation.
* Problem constraints and edge-case definitions.
* Execution metrics (Time & Space complexity, synchronized in real-time).

### Snippets

**Arrays & Hashing &mdash; Two Sum:**
```python
from arrays.two_sum import two_sum

nums = [2, 7, 11, 15]
print(two_sum(nums, 9))
# Output: [0, 1]
```

**Prefix Sum &mdash; State-Space Accumulation:**
```python
# Abstract pattern representation for O(1) range queries
nums = [1, 2, 3, 4]
prefix = [0] * (len(nums) + 1)

for i in range(len(nums)):
    prefix[i + 1] = prefix[i] + nums[i]

print(prefix[1:]) 
# Output: [1, 3, 6, 10]
```

**Bit Manipulation — Bitwise Operations Engine:**
```javascript
// Executed strictly via bitwise state shifts to bypass heavy arithmetic
const n = 16; // 10000 in binary
const isPowerOfTwo = (n > 0) && ((n & (n - 1)) === 0);

console.log(isPowerOfTwo);
// Output: true
```

**Cyclic Sort &mdash; First Missing Positive (O(1) Auxiliary Space):**
```javascript
const { firstMissingPositive } = require('./Cyclic_Sort/first_missing_positive');

const nums = [3, 4, -1, 1];
console.log(firstMissingPositive(nums));
// Output: 2
```

**Backtracking &mdash; Generate Parentheses:**
```javascript
const { generateParenthesis } = require('./backtracking/gen_parentheses');

const n = 3;
console.log(generateParenthesis(n));
// Output: [ '((()))', '(()())', '(())()', '()(())', '()()()' ]
```

**Binary Search &mdash; Median of Two Sorted Arrays:**
```cpp
#include "binary_search/median_sorted_arrays.h"

std::vector<int> nums1 = {1, 3};
std::vector<int> nums2 = {2};
std::cout << findMedianSortedArrays(nums1, nums2) << std::endl;
// Output: 2.0
```

**Dynamic Programming &mdash; Regular Expression Matching:**
```python
from dynamic_programming.regex_matching import is_match

string_val = "aab"
pattern = "c*a*b"
print(is_match(string_val, pattern))
# Output: True
```

**Game Theory &mdash; Sum Game:**
```javascript
const { sumGame } = require('./game_theory/sum_game');

const num = "?3295???";
console.log(sumGame(num));
// Output: false
```

**Linked Lists &mdash; Reverse Nodes in k-Group:**
```javascript
const { reverseKGroup, createList } = require('./linked_lists/reverse_k_group');

const head = createList([1, 2, 3, 4, 5]);
console.log(reverseKGroup(head, 2));
// Output: [2, 1, 4, 3, 5]
```

**Greedy — Jump Game II (O(N) Optimization):**
```cpp
#include "greedy/jump_game_ii.h"

std::vector<int> nums = {2, 3, 1, 1, 4};
std::cout << jump(nums) << std::endl;
// Output: 2
```

**Math — Roman to Integer:**
```cpp
#include "math/roman_to_integer.h"

std::string numeral = "MCMXCIV";
std::cout << romanToInt(numeral) << std::endl;
// Output: 1994
```

**Segment Tree &mdash; Longest Repeating Substring:**
```javascript
const { longestRepeatingSubstring } = require('./segment_tree/longest_repeat_substr');

const s = "abbaba";
console.log(longestRepeatingSubstring(s));
// Output: 2
```

**Sliding Window &mdash; Longest Substring Without Repeating Characters:**
```python
from sliding_window.longest_substring import length_of_longest_substring

text = "abcabcbb"
print(length_of_longest_substring(text))
# Output: 3
```

**Stacks &mdash; Valid Parentheses:**
```javascript
const { isValid } = require('./stacks/valid_parentheses');

const brackets = "()[]{}";
console.log(isValid(brackets));
// Output: true
```

**Strings &mdash; String to Integer (atoi):**
```cpp
#include "strings/string_to_integer_atoi.h"

std::string input = "   -42";
std::cout << myAtoi(input) << std::endl;
// Output: -42
```

**Two Pointers &mdash; Container With Most Water:**
```python
from two_pointers.container_with_most_water import max_area

heights = [1, 8, 6, 2, 5, 4, 8, 3, 7]
print(max_area(heights))
# Output: 49
```

---

## Engineering Standards

All modules are engineered with a strict focus on system-level constraints:
* **Time Complexity:** Optimized for minimal asymptotic upper bounds.
* **Space Complexity:** Emphasis on strictly in-place modifications and zero-overhead auxiliary space allocation.
* **Taxonomy:** Arrays, Linked Lists, Two Pointers, Trees, Graphs, Dynamic Programming, and Advanced Heuristics.
---

## Automation Pipeline
This infrastructure relies on zero manual indexing. Solutions are integrated, compiled, and pushed in real-time upon successful boundary validation on the master platform via automated CI/CD synchronization workflows. 

---

## Computational Paradigms & Micro-Optimizations

Beyond adhering to standard asymptotic limits, this repository enforces strict execution protocols to bypass high-level runtime overheads (e.g., V8 engine garbage collection and heap fragmentation):

* **State-Space Pruning:** Aggressive mathematical termination of duplicate recursive branches and overlapping subproblems prior to execution.
* **In-Place Mutability:** Complete elimination of auxiliary tracking structures via granular pointer manipulation, cyclic swapping, and bitwise state shifts.
* **Runtime-Agnostic Arithmetic:** Utilizing direct ASCII memory access and bit-level operations to bypass heavy type-conversion latency inherent in higher-level languages.

---

## Local Execution

To benchmark implementations locally, deploy the following standard execution protocols:

**C++**
```bash
g++ -O3 -std=c++17 filename.cpp -o executable
./executable
```

**Python**
```bash
python3 filename.py
```

**JavaScript**
```bash
node filename.js
```
---

## Fault Tolerance

These modules are architected as isolated algorithmic functions stripped of redundant boilerplate. Local execution may encounter expected integration faults. Deploy the following protocols to override them:

* **Missing Entry Point (Execution Halt):** Core modules omit driver code. You must manually instantiate the `Solution` class within a standard `main()` function prior to local C++ compilation.
* **Memory Anomalies & Segmentation Faults:** To diagnose uninitialized pointers, out-of-bounds access, or stack smashing during local testing, enforce GCC memory sanitization:
  ```bash
  g++ -O3 -Wall -Wextra -fsanitize=address filename.cpp -o debug_exec
  ./debug_exec
  ```
* **V8 Module Resolution:** If JavaScript modules encounter require or scope faults when tested directly, ensure execution within a standardized Node.js sandbox or strip the export statements for raw script execution.

---

<br>
<div align="right">
  <b>Rudranarayan Jena</b><br>
  <i>Founder @ Voxion Labs</i>
</div>
