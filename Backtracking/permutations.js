/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var permute = function(nums) {
    const result = [];
    
    // The core recursive engine
    const backtrack = (start) => {
        // Base case: we've formed a complete permutation
        if (start === nums.length) {
            // Push a shallow copy of the current state
            result.push([...nums]);
            return;
        }
        
        for (let i = start; i < nums.length; i++) {
            // Swap current element with the target
            [nums[start], nums[i]] = [nums[i], nums[start]];
            
            // Recurse down the state space tree
            backtrack(start + 1);
            
            // Backtrack: revert the swap to restore original state
            [nums[start], nums[i]] = [nums[i], nums[start]];
        }
    };
    
    backtrack(0);
    return result;
};