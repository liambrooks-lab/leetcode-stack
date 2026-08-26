/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function(nums) {
    let max = nums[0];
    let current = nums[0];
    
    // Cached length and skipped the 0th index for raw execution speed
    for (let i = 1, len = nums.length; i < len; i++) {
        let n = nums[i];
        
        // Instant state reset using fast ternary branching
        current = current < 0 ? n : current + n;
        
        // Single conditional check
        if (current > max) max = current;
    }
    
    return max;
};