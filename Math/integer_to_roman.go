/*
{
  "problem_name": "Integer To Roman",
  "category": "Math",
  "time_complexity": "O(N)",
  "space_complexity": "O(1)"
}
*/

package math

import "strings"

// IntToRoman converts an integer to a roman numeral string.
func IntToRoman(num int) string {
	values := [...]int{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1}
	symbols := [...]string{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"}

	var sb strings.Builder
	sb.Grow(16) // Pre-allocate byte capacity to eliminate heap allocations

	for i := 0; i < len(values); i++ {
		for num >= values[i] {
			sb.WriteString(symbols[i])
			num -= values[i]
		}
	}

	return sb.String()
}

func intToRoman(num int) string {
	return IntToRoman(num)
}
