/*
{
  "problem_name": "Uniform Parity Array Ii",
  "category": "Math",
  "time_complexity": "O(N)",
  "space_complexity": "O(1)"
}
*/

package math

// UniformArray determines if all elements can be made to have equal parity.
func UniformArray(nums1 []int) bool {
	if len(nums1) == 0 {
		return true
	}

	minVal := nums1[0]
	hasOdd := nums1[0]%2 != 0

	// Single pass O(N) execution
	for _, val := range nums1[1:] {
		if val < minVal {
			minVal = val
		}
		if val%2 != 0 {
			hasOdd = true
		}
	}

	// If the absolute minimum is Even, and there's ANY Odd number, it's impossible
	if minVal%2 == 0 && hasOdd {
		return false
	}

	return true
}

func uniformArray(nums1 []int) bool {
	return UniformArray(nums1)
}

func UniformParityArrayII(nums1 []int) bool {
	return UniformArray(nums1)
}
