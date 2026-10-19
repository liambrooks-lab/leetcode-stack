/*
{
  "problem_name": "Divide Integers Alu",
  "category": "Math",
  "time_complexity": "O(N)",
  "space_complexity": "O(1)"
}
*/

package math

// Divide divides two integers without using multiplication, division, and mod operator.
func Divide(dividend int, divisor int) int {
	const minInt = -2147483648
	const maxInt = 2147483647

	// Step 1: Overflow edge case
	if dividend == minInt && divisor == -1 {
		return maxInt
	}

	// Step 2: Extract the sign
	isNegative := (dividend < 0) != (divisor < 0)

	var num int64 = int64(dividend)
	if num < 0 {
		num = -num
	}
	var den int64 = int64(divisor)
	if den < 0 {
		den = -den
	}

	var quotient int64 = 0

	// Step 3 & 4: Exponential doubling and chunk subtraction
	for num >= den {
		temp := den
		var multiple int64 = 1

		for num >= (temp + temp) {
			temp += temp
			multiple += multiple
		}

		num -= temp
		quotient += multiple
	}

	// Step 5: Apply sign and bounds
	if isNegative {
		quotient = -quotient
	}

	if quotient > maxInt {
		return maxInt
	}
	if quotient < minInt {
		return minInt
	}
	return int(quotient)
}

func divide(dividend int, divisor int) int {
	return Divide(dividend, divisor)
}
