# leetcode-stack

[![Read in English](https://img.shields.io/badge/%F0%9F%8C%90_Read_in_English-1081c1?style=for-the-badge)](README.md)

---
> **एक ज़ीरो-टू-वन (0-to-1) एल्गोरिथम इंफ्रास्ट्रक्चर, जिसे स्टेट-स्पेस ऑप्टिमाइज़ेशन, एडवांस्ड डेटा स्ट्रक्चर इंजीनियरिंग और कंप्यूटेशनल एफिशिएंसी के लिए स्वतंत्र रूप से आर्किटेक्ट किया गया है।**

बिल्कुल ज़मीनी स्तर (ground up) से इंजीनियर की गई यह रिपॉजिटरी कठोर प्रॉब्लम-सॉल्विंग का एक व्यवस्थित आर्काइव है। हर एल्गोरिथम मॉड्यूल को न्यूनतम ऑक्ज़ीलियरी स्पेस (auxiliary space) और इष्टतम एसिम्प्टोटिक टाइम कॉम्प्लेक्सिटी (optimal asymptotic time complexity) लागू करने के लिए सख्ती से लिखा गया है, जो सीधे LeetCode प्लेटफॉर्म से निरंतर डिप्लॉयमेंट को दर्शाता है।

---

## द एग्जीक्यूशन स्टैक (The Execution Stack)

सॉल्यूशंस को एक ट्राई-लिंगुअल (tri-lingual) स्टैक के माध्यम से आर्किटेक्ट किया गया है, जिन्हें विशिष्ट कंप्यूटेशनल पैमानों के लिए रणनीतिक रूप से चुना गया है:

* **`C++`** &mdash; ग्रैन्युलर मेमोरी मैनेजमेंट, पॉइंटर अरिथमेटिक, और लो-लेटेंसी एग्जीक्यूशन।
* **`Python 3`** &mdash; रैपिड लॉजिक ऑर्केस्ट्रेशन, एडवांस्ड बिल्ट-इन डेटा स्ट्रक्चर्स, और गणितीय मॉडलिंग।
* **`JavaScript / Node.js`** &mdash; एसिंक्रोनस एग्जीक्यूशन पैटर्न्स और वेब-स्टैंडर्ड लॉजिक डिप्लॉयमेंट।

---

## आर्किटेक्चर और टैक्सोनॉमी

यह रिपॉजिटरी स्वायत्त (autonomously) रूप से मेंटेन की जाती है और सख्ती से एल्गोरिथम टैक्सोनॉमी के आधार पर संरचित है। प्रत्येक आइसोलेटेड मॉड्यूल में आमतौर पर शामिल हैं:
* रॉ (raw) सोर्स कोड इम्प्लीमेंटेशन।
* प्रॉब्लम कंस्ट्रेंट्स और एज-केस डेफिनेशन्स।
* एग्जीक्यूशन मेट्रिक्स (टाइम और स्पेस कॉम्प्लेक्सिटी, रीयल-टाइम में सिंक्रोनाइज़्ड)।

### स्निपेट्स (Snippets)

**एरेज़ (Arrays) &mdash; स्टेट-स्पेस ग्रुपिंग:**
```python
from arrays.lexicographically_smallest_array import lexicographically_smallest_array

nums = [1, 5, 3, 9, 8]
print(lexicographically_smallest_array(nums, 2))
# Output: [1, 3, 5, 8, 9]
```

**बैकट्रैकिंग (Backtracking) &mdash; पैरेन्थेसिस जनरेशन:**
```javascript
const { generateParenthesis } = require('./backtracking/gen_parentheses');

const n = 3;
console.log(generateParenthesis(n));
// Output: [ '((()))', '(()())', '(())()', '()(())', '()()()' ]
```

**बाइनरी सर्च (Binary Search) &mdash; दो सॉर्टेड एरेज़ का मीडियन:**
```cpp
#include "binary_search/median_sorted_arrays.h"

std::vector<int> nums1 = {1, 3};
std::vector<int> nums2 = {2};
std::cout << findMedianSortedArrays(nums1, nums2) << std::endl;
// Output: 2.0
```

**बिट मैनिपुलेशन (Bit Manipulation) — बिटवाइज़ ऑपरेशंस इंजन:**
```javascript
// Executed strictly via bitwise state shifts to bypass heavy arithmetic
const n = 16; // 10000 in binary
const isPowerOfTwo = (n > 0) && ((n & (n - 1)) === 0);

console.log(isPowerOfTwo);
// Output: true
```

**साइक्लिक सॉर्ट (Cyclic Sort) &mdash; फर्स्ट मिसिंग पॉज़िटिव (O(1) ऑक्ज़ीलियरी स्पेस):**
```javascript
const { firstMissingPositive } = require('./Cyclic_Sort/first_missing_positive');

const nums = [3, 4, -1, 1];
console.log(firstMissingPositive(nums));
// Output: 2
```

**डायनामिक प्रोग्रामिंग (Dynamic Programming) &mdash; रेगुलर एक्सप्रेशन मैचिंग:**
```python
from dynamic_programming.regex_matching import is_match

string_val = "aab"
pattern = "c*a*b"
print(is_match(string_val, pattern))
# Output: True
```

**गेम थ्योरी (Game Theory) &mdash; सम गेम:**
```javascript
const { sumGame } = require('./game_theory/sum_game');

const num = "?3295???";
console.log(sumGame(num));
// Output: false
```

**ग्राफ्स (Graphs) — स्टेट-स्पेस ट्रैवर्सल और कनेक्टिविटी:**
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

**ग्रीडी (Greedy) — जंप गेम II (O(N) ऑप्टिमाइज़ेशन):**
```cpp
#include "greedy/jump_game_ii.h"

std::vector<int> nums = {2, 3, 1, 1, 4};
std::cout << jump(nums) << std::endl;
// Output: 2
```

**हैशिंग (Hashing) &mdash; O(1) प्रोबेबिलिस्टिक लुकअप्स:**
```python
from hashing.two_sum import two_sum

nums = [2, 7, 11, 15]
print(two_sum(nums, 9))
# Output: [0, 1]
```

**इंटरवल (Intervals) &mdash; इन-प्लेस बाउंड्री मर्जिंग:**
```python
from intervals.merge_intervals import merge

intervals = [[1, 3], [2, 6], [8, 10], [15, 18]]
print(merge(intervals))
# Output: [[1, 6], [8, 10], [15, 18]]
```

**लिंक्ड लिस्ट्स (Linked Lists) &mdash; रिवर्स नोड्स इन k-ग्रुप:**
```javascript
const { reverseKGroup, createList } = require('./linked_lists/reverse_k_group');

const head = createList([1, 2, 3, 4, 5]);
console.log(reverseKGroup(head, 2));
// Output: [2, 1, 4, 3, 5]
```

**मैथ (Math) — रोमन टू इंटीजर:**
```cpp
#include "math/roman_to_integer.h"

std::string numeral = "MCMXCIV";
std::cout << romanToInt(numeral) << std::endl;
// Output: 1994
```

**मैट्रिसेस (Matrices) &mdash; O(1) स्पेस 2D ट्रैवर्सल:**
```python
from matrices.spiral_matrix import spiral_order

matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
print(spiral_order(matrix))
# Output: [1, 2, 3, 6, 9, 8, 7, 4, 5]
```

**प्रीफिक्स सम (Prefix Sum) &mdash; स्टेट-स्पेस एक्यूमुलेशन:**
```python
# Abstract pattern representation for O(1) range queries
nums = [1, 2, 3, 4]
prefix = [0] * (len(nums) + 1)

for i in range(len(nums)):
    prefix[i + 1] = prefix[i] + nums[i]

print(prefix[1:]) 
# Output: [1, 3, 6, 10]
```

**सेगमेंट ट्री (Segment Tree) &mdash; लॉन्गेस्ट रिपीटिंग सबस्ट्रिंग:**
```javascript
const { longestRepeatingSubstring } = require('./segment_tree/longest_repeat_substr');

const s = "abbaba";
console.log(longestRepeatingSubstring(s));
// Output: 2
```

**स्लाइडिंग विंडो (Sliding Window) &mdash; लॉन्गेस्ट सबस्ट्रिंग विदाउट रिपीटिंग कैरेक्टर्स:**
```python
from sliding_window.longest_substring import length_of_longest_substring

text = "abcabcbb"
print(length_of_longest_substring(text))
# Output: 3
```

**स्टैक्स (Stacks) &mdash; वैलिड पैरेन्थेसिस:**
```javascript
const { isValid } = require('./stacks/valid_parentheses');

const brackets = "()[]{}";
console.log(isValid(brackets));
// Output: true
```

**स्ट्रिंग्स (Strings) &mdash; स्ट्रिंग टू इंटीजर (atoi):**
```cpp
#include "strings/string_to_integer_atoi.h"

std::string input = "   -42";
std::cout << myAtoi(input) << std::endl;
// Output: -42
```

**ट्रीज़ (Trees) &mdash; O(N) पोस्ट-ऑर्डर स्टेट इवैल्यूएशन:**
```python
from trees.subtree_average import average_of_subtree

# Abstract tree node architecture
# Root mapping: [4,8,5,0,1,null,6]
print(average_of_subtree(root))
# Output: 5
```

**टू पॉइंटर्स (Two Pointers) &mdash; कंटेनर विद मोस्ट वाटर:**
```python
from two_pointers.container_with_most_water import max_area

heights = [1, 8, 6, 2, 5, 4, 8, 3, 7]
print(max_area(heights))
# Output: 49
```

---

## इंजीनियरिंग स्टैंडर्ड्स (Engineering Standards)

सभी मॉड्यूल्स को सिस्टम-लेवल कंस्ट्रेंट्स पर सख्त फोकस के साथ इंजीनियर किया गया है:
* **टाइम कॉम्प्लेक्सिटी:** न्यूनतम एसिम्प्टोटिक अपर बाउंड्स के लिए ऑप्टिमाइज़्ड।
* **स्पेस कॉम्प्लेक्सिटी:** पूरी तरह से इन-प्लेस मोडिफिकेशन्स और ज़ीरो-ओवरहेड ऑक्ज़ीलियरी स्पेस एलोकेशन पर ज़ोर।
* **टैक्सोनॉमी:** Arrays, Backtracking, Binary Search, Bit Manipulation, Cyclic Sort, Dynamic Programming, Game Theory, Graphs, Greedy, Hashing, Intervals, Linked Lists, Math, Matrices, Prefix Sum, Segment Tree, Sliding Window, Stacks, Strings, Trees, और Two Pointers में व्यापक कवरेज।

---

## ऑटोमेशन पाइपलाइन

यह इंफ्रास्ट्रक्चर ज़ीरो मैनुअल इंडेक्सिंग पर निर्भर करता है। ऑटोमेटेड CI/CD सिंक्रोनाइज़ेशन वर्कफ़्लो के माध्यम से मास्टर प्लेटफॉर्म पर सफल बाउंड्री वैलिडेशन के बाद सॉल्यूशंस को रीयल-टाइम में इंटीग्रेट, कंपाइल और पुश किया जाता है। हमारा कस्टम टेस्ट, लिंटिंग, और बेयर-मेटल बेंचमार्किंग आर्किटेक्चर GitHub Actions के ज़रिए त्रुटिहीन (flawlessly) काम करता है।

---

## कंप्यूटेशनल पैराडाइम्स और माइक्रो-ऑप्टिमाइज़ेशन्स

मानक एसिम्प्टोटिक लिमिट्स का पालन करने के अलावा, यह रिपॉजिटरी हाई-लेवल रनटाइम ओवरहेड्स (जैसे V8 इंजन गार्बेज कलेक्शन और हीप फ्रैगमेंटेशन) को बायपास करने के लिए सख्त एग्जीक्यूशन प्रोटोकॉल लागू करती है:

* **स्टेट-स्पेस प्रूनिंग:** एग्जीक्यूशन से पहले डुप्लीकेट रिकर्सिव ब्रांचेस और ओवरलैपिंग सबप्रॉब्लम्स का आक्रामक गणितीय टर्मिनेशन (termination)।
* **इन-प्लेस म्यूटेबिलिटी:** ग्रैन्युलर पॉइंटर मैनिपुलेशन, साइक्लिक स्वैपिंग और बिटवाइज़ स्टेट शिफ्ट्स के ज़रिए ऑक्ज़ीलियरी ट्रैकिंग स्ट्रक्चर्स का पूर्ण उन्मूलन (elimination)।
* **रनटाइम-एग्नोस्टिक अरिथमेटिक:** हाई-लेवल भाषाओं में मौजूद भारी टाइप-कन्वर्ज़न लेटेंसी को बायपास करने के लिए सीधे ASCII मेमोरी एक्सेस और बिट-लेवल ऑपरेशंस का उपयोग।

---

## लोकल एग्जीक्यूशन (Local Execution)

इम्प्लीमेंटेशन्स को लोकली बेंचमार्क करने के लिए, निम्नलिखित स्टैंडर्ड एग्जीक्यूशन प्रोटोकॉल्स डिप्लॉय करें:

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

## फॉल्ट टॉलरेंस (Fault Tolerance)

इन मॉड्यूल्स को अनावश्यक बॉयलरप्लेट से मुक्त आइसोलेटेड एल्गोरिथम फ़ंक्शन्स के रूप में आर्किटेक्ट किया गया है। लोकल एग्जीक्यूशन में अपेक्षित इंटीग्रेशन फॉल्ट्स आ सकते हैं। उन्हें ओवरराइड करने के लिए निम्नलिखित प्रोटोकॉल डिप्लॉय करें:

* **मिसिंग एंट्री पॉइंट:** कोर मॉड्यूल्स में ड्राइवर कोड नहीं होता है। आपको लोकल C++ कंपाइलेशन से पहले एक स्टैंडर्ड `main()` फ़ंक्शन के भीतर मैन्युअली `Solution` क्लास को इंस्टेंशिएट (instantiate) करना होगा।
* **मेमोरी एनोमलीज़ और सेगमेंटेशन फॉल्ट्स:** अनइनिशियलाइज़्ड पॉइंटर्स, आउट-ऑफ़-बाउंड्स एक्सेस, या स्टैक स्मैशिंग को डायग्नोस करने के लिए, GCC मेमोरी सैनिटाइज़ेशन लागू करें:
  ```bash
  g++ -O3 -Wall -Wextra -fsanitize=address filename.cpp -o debug_exec
  ./debug_exec
  ```
* **V8 मॉड्यूल रिज़ॉल्यूशन:** यदि JavaScript मॉड्यूल्स को सीधे टेस्ट करते समय रिक्वायर या स्कोप फॉल्ट्स आते हैं, तो सुनिश्चित करें कि एग्जीक्यूशन एक स्टैंडर्डाइज़्ड Node.js सैंडबॉक्स के भीतर हो, या रॉ स्क्रिप्ट एग्जीक्यूशन के लिए एक्सपोर्ट स्टेटमेंट्स हटा दें।

---

<br>
<div align="right">
  <b>Rudranarayan Jena</b><br>
  <i>Founder @ Voxion Labs</i>
</div>