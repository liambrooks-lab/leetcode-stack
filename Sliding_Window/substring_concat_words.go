/*
{
  "problem_name": "Substring Concat Words",
  "category": "Sliding_Window",
  "time_complexity": "O(N)",
  "space_complexity": "O(1)"
}
*/

package slidingwindow

// FindSubstring finds all starting indices of substring(s) in s that is a concatenation of each word in words exactly once.
func FindSubstring(s string, words []string) []int {
	if len(s) == 0 || len(words) == 0 {
		return []int{}
	}

	wordLen := len(words[0])
	wordCount := len(words)
	totalLen := wordLen * wordCount
	if len(s) < totalLen {
		return []int{}
	}

	var result []int

	// Step 1: Frequency map for required words
	wordMap := make(map[string]int, wordCount)
	for _, word := range words {
		wordMap[word]++
	}

	// Step 2: Loop through possible word offsets
	for i := 0; i < wordLen; i++ {
		left := i
		right := i
		currentMap := make(map[string]int, wordCount)
		count := 0

		// Step 3: Expand the sliding window
		for right+wordLen <= len(s) {
			word := s[right : right+wordLen]
			right += wordLen

			// Step 4: Validate extracted word
			if reqCount, exists := wordMap[word]; exists {
				currentMap[word]++
				count++

				// Shrink the window if word appears more times than required
				for currentMap[word] > reqCount {
					leftWord := s[left : left+wordLen]
					currentMap[leftWord]--
					count--
					left += wordLen
				}

				// If all words matched, record starting index
				if count == wordCount {
					result = append(result, left)
				}
			} else {
				// Invalid word breaks sequence; reset
				clear(currentMap)
				count = 0
				left = right
			}
		}
	}

	return result
}

func findSubstring(s string, words []string) []int {
	return FindSubstring(s, words)
}
