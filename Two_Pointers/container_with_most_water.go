/*
{
  "problem_name": "Container With Most Water",
  "category": "Two_Pointers",
  "time_complexity": "O(N)",
  "space_complexity": "O(1)"
}
*/

package twopointers

// MaxArea finds two lines that together with the x-axis form a container containing the most water.
func MaxArea(height []int) int {
	left := 0
	right := len(height) - 1
	maxArea := 0

	for left < right {
		hLeft := height[left]
		hRight := height[right]

		currentHeight := hLeft
		if hRight < currentHeight {
			currentHeight = hRight
		}

		currentArea := currentHeight * (right - left)
		if currentArea > maxArea {
			maxArea = currentArea
		}

		// Skip inner lines shorter than or equal to current boundary
		if hLeft < hRight {
			for left < right && height[left] <= hLeft {
				left++
			}
		} else {
			for left < right && height[right] <= hRight {
				right--
			}
		}
	}

	return maxArea
}

func maxArea(height []int) int {
	return MaxArea(height)
}
