/*
{
    "problem_name": "Count Days Spent Together",
    "category": "Intervals / Math",
    "time_complexity": "O(1) -> Bare-metal byte parsing and direct arithmetic lookups. Bypasses all standard string/time library overheads.",
    "space_complexity": "O(1) -> Strict constant space. Zero dynamic memory allocations, using a static prefix array."
}
*/
package main

// Precomputed prefix sum of days before the start of each month (non-leap year)
var prefixDays = [...]int{0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334}

// parseDate converts "MM-DD" directly to the day of the year (1 to 365) in O(1) time
func parseDate(date string) int {
	// Bypassing string splitting and Atoi overhead by reading bytes directly
	m := int((date[0]-'0')*10 + (date[1]-'0'))
	d := int((date[3]-'0')*10 + (date[4]-'0'))
	return prefixDays[m-1] + d
}

func countDaysTogether(arriveAlice string, leaveAlice string, arriveBob string, leaveBob string) int {
	startA := parseDate(arriveAlice)
	endA := parseDate(leaveAlice)
	startB := parseDate(arriveBob)
	endB := parseDate(leaveBob)

	// Calculate intersection overlap bounds
	start := startA
	if startB > startA {
		start = startB
	}

	end := endA
	if endB < endA {
		end = endB
	}

	// If the overlap interval is valid, return the number of days (inclusive)
	if start <= end {
		return end - start + 1
	}

	return 0
}