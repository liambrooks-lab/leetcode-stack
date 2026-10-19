/*
{
  "problem_name": "Shortest Beautiful Substring",
  "category": "Strings",
  "time_complexity": "O(N)",
  "space_complexity": "O(1)"
}
*/

package strings

// ShortestBeautifulSubstring finds the shortest beautiful substring with exactly k '1's.
func ShortestBeautifulSubstring(s string, k int) string {
	minimumLengthFound := len(s) + 1
	finalResultString := ""
	leftPointer := 0
	currentOneCounter := 0

	for rightPointer := 0; rightPointer < len(s); rightPointer++ {
		if s[rightPointer] == '1' {
			currentOneCounter++
		}

		for currentOneCounter == k {
			currentWindowLen := rightPointer - leftPointer + 1
			currentSubstringValue := s[leftPointer : rightPointer+1]

			if currentWindowLen < minimumLengthFound {
				minimumLengthFound = currentWindowLen
				finalResultString = currentSubstringValue
			} else if currentWindowLen == minimumLengthFound {
				if currentSubstringValue < finalResultString {
					finalResultString = currentSubstringValue
				}
			}

			if s[leftPointer] == '1' {
				currentOneCounter--
			}
			leftPointer++
		}
	}

	return finalResultString
}

func shortestBeautifulSubstring(s string, k int) string {
	return ShortestBeautifulSubstring(s, k)
}
