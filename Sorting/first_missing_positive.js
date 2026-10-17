/*
{
  "problem_name": "First Missing Positive",
  "category": "Cyclic_Sort",
  "time_complexity": "O(N)",
  "space_complexity": "O(1)"
}
*/
/**
 * @param {number[]} nums
 * @return {number}
 */
var firstMissingPositive = function(nums) {
    const n = nums.length; // Cache length to bypass object lookups
    
    for (let i = 0; i < n; i++) {
        // We only care about positive numbers within the bounds of the array
        // We keep swapping until the number at nums[i] is at its correct index
        while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] !== nums[i]) {
            // Find the correct index for this number
            let correctPos = nums[i] - 1;
            
            // Native primitive swap (avoids destructuring overhead in V8)
            let temp = nums[correctPos];
            nums[correctPos] = nums[i];
            nums[i] = temp;
        }
    }
    
    // Final linear scan to find the first missing element
    for (let i = 0; i < n; i++) {
        if (nums[i] !== i + 1) {
            return i + 1; // Found the gap!
        }
    }
    
    // If all numbers from 1 to n are perfectly placed, the missing is n + 1
    return n + 1;
};