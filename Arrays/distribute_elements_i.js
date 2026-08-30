/**
 * @param {number[]} nums
 * @return {number[]}
 */
var resultArray = function(nums) {
    let arr1 = [nums[0]];
    let arr2 = [nums[1]];
    
    // Cache the last elements directly into memory registers
    let last1 = nums[0];
    let last2 = nums[1];
    
    for (let i = 2; i < nums.length; i++) {
        let val = nums[i];
        
        // Zero array property lookups! Just pure primitive comparison.
        if (last1 > last2) {
            arr1.push(val);
            last1 = val; // Update cache
        } else {
            arr2.push(val);
            last2 = val; // Update cache
        }
    }
    
    return arr1.concat(arr2);
};