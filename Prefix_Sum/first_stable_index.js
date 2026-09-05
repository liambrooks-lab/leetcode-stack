/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var firstStableIndex = function(nums, k) {
    const n = nums.length;
    
    // V8 Engine Optimization: Contiguous memory allocation for suffix tracking
    // Easily scales to 10^5 without fragmentation
    const minRight = new Int32Array(n);
    
    // Phase 1: Suffix Min Precomputation - O(N)
    let currentMin = 2e9; 
    for (let i = n - 1; i >= 0; i--) {
        if (nums[i] < currentMin) {
            currentMin = nums[i];
        }
        minRight[i] = currentMin;
    }
    
    // Phase 2: Running Prefix Max & Instant Evaluation - O(N)
    let maxLeft = -2e9;
    for (let i = 0; i < n; i++) {
        if (nums[i] > maxLeft) {
            maxLeft = nums[i];
        }
        
        // Zero-overhead state check
        if (maxLeft - minRight[i] <= k) {
            return i;
        }
    }
    
    return -1;
};