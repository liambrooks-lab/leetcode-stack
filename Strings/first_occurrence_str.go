/*
{
  "problem_name": "First Occurrence Str",
  "category": "Strings",
  "time_complexity": "O(N)",
  "space_complexity": "O(1)"
}
*/

package strings

import "strings"

// StrStr returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
func StrStr(haystack string, needle string) int {
	return strings.Index(haystack, needle)
}

func strStr(haystack string, needle string) int {
	return StrStr(haystack, needle)
}
