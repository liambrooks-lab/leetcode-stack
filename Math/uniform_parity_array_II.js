/**
 * @param {number[]} nums1
 * @return {boolean}
 */
var uniformArray = function(nums1) {
    let minVal = Infinity;
    let hasOdd = false;

    // Single pass O(N) execution to completely bypass V8 call stack limits
    for (let i = 0; i < nums1.length; i++) {
        if (nums1[i] < minVal) {
            minVal = nums1[i];
        }
        if (nums1[i] % 2 !== 0) {
            hasOdd = true;
        }
    }

    // If the absolute minimum is Even, and there's ANY Odd number, it's a mathematical deadlock
    if (minVal % 2 === 0 && hasOdd) {
        return false;
    }

    return true;
};