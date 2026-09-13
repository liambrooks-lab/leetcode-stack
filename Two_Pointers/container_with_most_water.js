/*
{
  "problem_name": "Container With Most Water",
  "category": "Two_Pointers",
  "time_complexity": "O(N)",
  "space_complexity": "O(1)"
}
*/
/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function(height) {
    let left = 0;
    let right = height.length - 1;
    let maxArea = 0;

    while (left < right) {
        // Cache variables to avoid repeated array property lookups
        let hLeft = height[left];
        let hRight = height[right];
        
        // Manual calculation to bypass Math.min() overhead
        let currentHeight = hLeft < hRight ? hLeft : hRight;
        let currentArea = currentHeight * (right - left);
        
        // Manual check to bypass Math.max() overhead
        if (currentArea > maxArea) {
            maxArea = currentArea;
        }
        // Skip all inner lines that are shorter or equal to the current one
        if (hLeft < hRight) {
            while (left < right && height[left] <= hLeft) {
                left++;
            }
        } else {
            while (left < right && height[right] <= hRight) {
                right--;
            }
        }
    }

    return maxArea;
};