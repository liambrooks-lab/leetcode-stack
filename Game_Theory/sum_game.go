/*
{
  "problem_name": "Sum Game",
  "category": "Game_Theory",
  "time_complexity": "O(N)",
  "space_complexity": "O(1)"
}
*/

package gametheory

// SumGame determines if Alice can win the sum game on a numerical string with '?' placeholders.
func SumGame(num string) bool {
	n := len(num)
	half := n / 2

	leftSum, rightSum := 0, 0
	leftQ, rightQ := 0, 0

	for i := 0; i < half; i++ {
		if num[i] == '?' {
			leftQ++
		} else {
			leftSum += int(num[i] - '0')
		}
	}

	for i := half; i < n; i++ {
		if num[i] == '?' {
			rightQ++
		} else {
			rightSum += int(num[i] - '0')
		}
	}

	if (leftQ+rightQ)%2 == 1 {
		return true
	}

	// Mathematical parity: Bob can only neutralize if the sum difference matches question mark parity times 9 / 2
	return (leftSum - rightSum) != ((rightQ-leftQ)/2)*9
}

func sumGame(num string) bool {
	return SumGame(num)
}
