/*
{
  "problem_name": "Valid Parentheses",
  "category": "Stacks",
  "time_complexity": "O(N)",
  "space_complexity": "O(1)"
}
*/

package stacks

// IsValid determines if the input string containing brackets is valid.
func IsValid(s string) bool {
	n := len(s)
	if n%2 != 0 {
		return false
	}

	// Pre-allocate slice with capacity up to n/2 to eliminate GC reallocation
	stack := make([]byte, 0, n)

	for i := 0; i < n; i++ {
		c := s[i]
		if c == '(' || c == '{' || c == '[' {
			stack = append(stack, c)
			continue
		}

		if len(stack) == 0 {
			return false
		}

		open := stack[len(stack)-1]
		stack = stack[:len(stack)-1]

		if (open == '(' && c != ')') ||
			(open == '{' && c != '}') ||
			(open == '[' && c != ']') {
			return false
		}
	}

	return len(stack) == 0
}

func isValid(s string) bool {
	return IsValid(s)
}
