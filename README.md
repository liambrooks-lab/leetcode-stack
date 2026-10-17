# leetcode-stack

[![Read in English](https://img.shields.io/badge/%F0%9F%8C%90_Read_in_English-1081c1?style=for-the-badge)](https://github.com/liambrooks-lab/leetcode-stack/blob/main/README.md)

---
> **एक शून्य-से-शिखर (0-to-1) तक की कलन विधि (algorithmic) अवसंरचना, जिसे अवस्था-समष्टि अनुकूलन (state-space optimization), उन्नत आँकड़ा संरचना अभियांत्रिकी (advanced data structure engineering) और संगणनात्मक दक्षता (computational efficiency) के लिए स्वतंत्र रूप से निर्मित किया गया है।**

पूर्णतः आधारभूत स्तर (ground up) से निर्मित यह संग्रह (repository) कठोर समस्या-समाधान का एक व्यवस्थित अभिलेखागार (archive) है। प्रत्येक कलन विधि मॉड्यूल को न्यूनतम सहायक स्थान (auxiliary space) और इष्टतम अनंतस्पर्शी समय जटिलता (optimal asymptotic time complexity) सुनिश्चित करने के लिए कड़ाई से लिखा गया है, जो लीटकोड (LeetCode) मंच से निरंतर परिनियोजन (deployment) को दर्शाता है।

---

## निष्पादन प्रौद्योगिकी (The Execution Stack)

समाधानों को त्रि-भाषीय संरचना के माध्यम से निर्मित किया गया है, जिन्हें विशिष्ट संगणनात्मक प्रतिमानों के लिए रणनीतिक रूप से चुना गया है:

* **`C++`** &mdash; सूक्ष्म स्मृति प्रबंधन (granular memory management), सूचक अंकगणित (pointer arithmetic), और निम्न-विलंबता निष्पादन (low-latency execution)।
* **`Python 3`** &mdash; त्वरित तर्क संयोजन, उन्नत अंतर्निहित आँकड़ा संरचनाएँ, और गणितीय प्रतिरूपण।
* **`JavaScript / Node.js`** &mdash; अतुल्यकालिक (asynchronous) निष्पादन प्रणाली और वेब-मानक तर्क परिनियोजन।

---

## वास्तुकला और वर्गीकरण (Architecture & Taxonomy)

यह संग्रह स्वायत्त रूप से प्रबंधित है और कलन विधि वर्गीकरण के आधार पर कड़ाई से संरचित है। प्रत्येक पृथक मॉड्यूल में आमतौर पर शामिल हैं:
* मूल स्रोत कूट (source code) कार्यान्वयन।
* समस्या की सीमाएँ (constraints) और सीमांत-स्थिति (edge-case) परिभाषाएँ।
* निष्पादन मापदंड (समय और स्थान जटिलता, वास्तविक समय में समकालिक)।

### कोड के अंश (Snippets)

**व्यूह (Arrays) &mdash; अवस्था-समष्टि समूहीकरण (State-Space Grouping):**
```python
from arrays.lexicographically_smallest_array import lexicographically_smallest_array

nums = [1, 5, 3, 9, 8]
print(lexicographically_smallest_array(nums, 2))
# Output: [1, 3, 5, 8, 9]
```

**पश्चमार्ग-अनुसरण (Backtracking) &mdash; कोष्ठक निर्माण (Generate Parentheses):**
```javascript
const { generateParenthesis } = require('./backtracking/gen_parentheses');

const n = 3;
console.log(generateParenthesis(n));
// Output: [ '((()))', '(()())', '(())()', '()(())', '()()()' ]
```

**द्विआधारी अनुक्रमित वृक्ष (Binary Indexed Tree) &mdash; योग वर्ग विशिष्ट गणना (Dual-BIT):**
```cpp
#include "binary_indexed_tree/sum_squares_distinct_counts_hard.h"

std::vector<int> nums = {1, 2, 1};
Solution sol;
std::cout << sol.sumCounts(nums) << std::endl;
// Output: 15
```

**द्विआधारी खोज (Binary Search) &mdash; दो क्रमबद्ध सरणियों की माध्यिका:**
```cpp
#include "binary_search/median_sorted_arrays.h"

std::vector<int> nums1 = {1, 3};
std::vector<int> nums2 = {2};
std::cout << findMedianSortedArrays(nums1, nums2) << std::endl;
// Output: 2.0
```

**बिट हेरफेर (Bit Manipulation) — बिटवाइज़ संक्रियाएँ इंजन:**
```javascript
// Executed strictly via bitwise state shifts to bypass heavy arithmetic
const n = 16; // 10000 in binary
const isPowerOfTwo = (n > 0) && ((n & (n - 1)) === 0);

console.log(isPowerOfTwo);
// Output: true
```

**गतिशील क्रमादेशन (Dynamic Programming) &mdash; नियमित अभिव्यक्ति मिलान:**
```python
from dynamic_programming.regex_matching import is_match

string_val = "aab"
pattern = "c*a*b"
print(is_match(string_val, pattern))
# Output: True
```

**खेल सिद्धांत (Game Theory) &mdash; योग का खेल:**
```javascript
const { sumGame } = require('./game_theory/sum_game');

const num = "?3295???";
console.log(sumGame(num));
// Output: false
```

**आलेख (Graphs) — अवस्था-समष्टि ट्रैवर्सल और कनेक्टिविटी:**
```cpp
#include "Graphs/graph.h"

Graph graph(5);

graph.addEdge(0, 1);
graph.addEdge(0, 2);
graph.addEdge(1, 3);
graph.addEdge(2, 3);
graph.addEdge(3, 4);

graph.traverse(0);
// Output: 0 1 2 3 4
```

**लालची दृष्टिकोण (Greedy) — छलांग का खेल II (O(N) अनुकूलन):**
```cpp
#include "greedy/jump_game_ii.h"

std::vector<int> nums = {2, 3, 1, 1, 4};
std::cout << jump(nums) << std::endl;
// Output: 2
```

**हैशिंग (Hashing) &mdash; O(1) संभाव्य खोज:**
```python
from hashing.two_sum import two_sum

nums = [2, 7, 11, 15]
print(two_sum(nums, 9))
# Output: [0, 1]
```

**अंतराल (Intervals) &mdash; यथास्थान सीमा विलय:**
```python
from intervals.merge_intervals import merge

intervals = [[1, 3], [2, 6], [8, 10], [15, 18]]
print(merge(intervals))
# Output: [[1, 6], [8, 10], [15, 18]]
```

**श्रृंखलाबद्ध सूचियाँ (Linked Lists) &mdash; k-समूह में नोड्स को उलटना:**
```javascript
const { reverseKGroup, createList } = require('./linked_lists/reverse_k_group');

const head = createList([1, 2, 3, 4, 5]);
console.log(reverseKGroup(head, 2));
// Output: [2, 1, 4, 3, 5]
```

**गणित (Math) — रोमन से पूर्णांक:**
```cpp
#include "math/roman_to_integer.h"

std::string numeral = "MCMXCIV";
std::cout << romanToInt(numeral) << std::endl;
// Output: 1994
```

**आव्यूह (Matrices) &mdash; O(1) स्थान 2D ट्रैवर्सल:**
```python
from matrices.spiral_matrix import spiral_order

matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
print(spiral_order(matrix))
# Output: [1, 2, 3, 6, 9, 8, 7, 4, 5]
```

**उपसर्ग योग (Prefix Sum) &mdash; अवस्था-समष्टि संचय:**
```python
# Abstract pattern representation for O(1) range queries
nums = [1, 2, 3, 4]
prefix = [0] * (len(nums) + 1)

for i in range(len(nums)):
    prefix[i + 1] = prefix[i] + nums[i]

print(prefix[1:]) 
# Output: [1, 3, 6, 10]
```

**खंड वृक्ष (Segment Tree) &mdash; सबसे लंबा दोहराव वाला उपसूत्र:**
```javascript
const { longestRepeatingSubstring } = require('./segment_tree/longest_repeat_substr');

const s = "abbaba";
console.log(longestRepeatingSubstring(s));
// Output: 2
```

**खिसकती खिड़की (Sliding Window) &mdash; बिना दोहराए वर्णों का सबसे लंबा उपसूत्र:**
```python
from sliding_window.longest_substring import length_of_longest_substring

text = "abcabcbb"
print(length_of_longest_substring(text))
# Output: 3
```

**छँटाई (Sorting) — क्रमबद्ध करने के लिए न्यूनतम स्वैप (चक्र पहचान):**
```cpp
#include "sorting/min_swaps_to_sort.h"

std::vector<int> nums = {18, 43, 34, 16};
Solution sol;
std::cout << sol.minSwaps(nums) << std::endl;
// Output: 2
```

**ढेर (Stacks) &mdash; मान्य कोष्ठक:**
```javascript
const { isValid } = require('./stacks/valid_parentheses');

const brackets = "()[]{}";
console.log(isValid(brackets));
// Output: true
```

**सूत्र (Strings) &mdash; सूत्र से पूर्णांक (atoi):**
```cpp
#include "strings/string_to_integer_atoi.h"

std::string input = "   -42";
std::cout << myAtoi(input) << std::endl;
// Output: -42
```

**वृक्ष (Trees) &mdash; O(N) पोस्ट-ऑर्डर अवस्था मूल्यांकन:**
```python
from trees.subtree_average import average_of_subtree

# Abstract tree node architecture
# Root mapping: [4,8,5,0,1,null,6]
print(average_of_subtree(root))
# Output: 5
```

**दो सूचक (Two Pointers) &mdash; अधिकतम जल वाला पात्र:**
```python
from two_pointers.container_with_most_water import max_area

heights = [1, 8, 6, 2, 5, 4, 8, 3, 7]
print(max_area(heights))
# Output: 49
```

---

## अभियांत्रिकी मानक (Engineering Standards)

सभी मॉड्यूल्स को प्रणाली-स्तरीय (system-level) सीमाओं पर सख्त ध्यान केंद्रित करते हुए निर्मित किया गया है:
* **समय जटिलता (Time Complexity):** न्यूनतम अनंतस्पर्शी ऊपरी सीमा के लिए अनुकूलित।
* **स्थान जटिलता (Space Complexity):** पूर्णतः यथास्थान (in-place) संशोधनों और शून्य-अतिरिक्त सहायक स्थान आवंटन पर ज़ोर।
* **वर्गीकरण (Taxonomy):** सरणियाँ (Arrays), पूर्व-खोज (Backtracking), द्विआधारी अनुक्रमित वृक्ष (Binary Indexed Tree), द्विआधारी खोज (Binary Search), बिट हेरफेर (Bit Manipulation), गतिशील क्रमादेशन (Dynamic Programming), खेल सिद्धांत (Game Theory), आलेख (Graphs), लालची दृष्टिकोण (Greedy), हैशिंग (Hashing), अंतराल (Intervals), श्रृंखलाबद्ध सूचियाँ (Linked Lists), गणित (Math), आव्यूह (Matrices), उपसर्ग योग (Prefix Sum), खंड वृक्ष (Segment Tree), खिसकती खिड़की (Sliding Window), छँटाई (Sorting), ढेर (Stacks), सूत्र (Strings), वृक्ष (Trees), और दो सूचक (Two Pointers) में व्यापक कवरेज।

---

## स्वचालन पाइपलाइन (Automation Pipeline)

यह अवसंरचना शून्य हस्तचालित अनुक्रमण (manual indexing) पर निर्भर करती है। स्वचालित CI/CD समकालन कार्यप्रवाह (workflows) के माध्यम से मुख्य मंच पर सफल सीमा सत्यापन के बाद समाधानों को वास्तविक समय में एकीकृत, संकलित और अद्यतित किया जाता है। हमारा अनुकूलित परीक्षण, लिंटिंग, और बेयर-मेटल बेंचमार्किंग ढांचा गिटहब एक्शंस (GitHub Actions) के ज़रिए त्रुटिहीन (flawlessly) रूप से कार्य करता है।

---

## संगणनात्मक प्रतिमान और सूक्ष्म-अनुकूलन (Computational Paradigms & Micro-Optimizations)

मानक अनंतस्पर्शी सीमाओं का पालन करने के अतिरिक्त, यह संग्रह उच्च-स्तरीय रनटाइम विलंब (जैसे V8 इंजन कचरा संग्रहण और हीप विखंडन) को दरकिनार करने के लिए सख्त निष्पादन आचार संहिताओं को लागू करता है:

* **अवस्था-समष्टि छँटाई (State-Space Pruning):** निष्पादन से पूर्व ही अवांछित पुनरावर्ती शाखाओं और अतिव्यापी उप-समस्याओं का आक्रामक गणितीय समापन।
* **यथास्थान परिवर्तनशीलता (In-Place Mutability):** सूक्ष्म सूचक हेरफेर (pointer manipulation), चक्रीय अदला-बदली और बिटवाइज़ अवस्था खिसकाव के ज़रिए सहायक ट्रैकिंग संरचनाओं का पूर्ण उन्मूलन।
* **रनटाइम-अज्ञेय अंकगणित (Runtime-Agnostic Arithmetic):** उच्च-स्तरीय भाषाओं में मौजूद भारी प्रकार-रूपांतरण (type-conversion) विलंबता से बचने के लिए सीधे ASCII स्मृति पहुँच और बिट-स्तरीय संक्रियाओं का उपयोग।

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

**JavaScript**
```bash
node filename.js
```

---

## त्रुटि सहिष्णुता (Fault Tolerance)

इन मॉड्यूलों को निरर्थक बॉयलरप्लेट (boilerplate) से मुक्त, पृथक कलन विधि कार्यों के रूप में संरचित किया गया है। स्थानीय निष्पादन में अपेक्षित एकीकरण त्रुटियाँ आ सकती हैं। उन्हें अधिरोहित (override) करने के लिए निम्नलिखित प्रोटोकॉल लागू करें:

* **अनुपस्थित प्रवेश बिंदु (Missing Entry Point):** मुख्य मॉड्यूलों में चालक (driver) कोड नहीं होता है। आपको स्थानीय C++ संकलन से पूर्व एक मानक `main()` फ़ंक्शन के भीतर मैन्युअली `Solution` क्लास को आरंभीकृत (instantiate) करना होगा।
* **स्मृति विसंगतियाँ और विखंडन त्रुटियाँ (Memory Anomalies & Segmentation Faults):** अनरंभीकृत सूचकों, सीमा-से-बाहर पहुँच, या स्टैक विनाश का निदान करने के लिए, GCC स्मृति स्वच्छता (memory sanitization) लागू करें:
  ```bash
  g++ -O3 -Wall -Wextra -fsanitize=address filename.cpp -o debug_exec
  ./debug_exec
  ```
* **V8 मॉड्यूल संकल्प:** यदि जावास्क्रिप्ट मॉड्यूलों को सीधे जांचते समय 'रिक्वायर' (require) या स्कोप त्रुटियाँ आती हैं, तो सुनिश्चित करें कि निष्पादन एक मानकीकृत Node.js सैंडबॉक्स के भीतर हो, या रॉ स्क्रिप्ट निष्पादन के लिए एक्सपोर्ट (export) कथनों को हटा दें।

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
 Leetcode · DSA · Python3 · C++ · Javascript
</p>
