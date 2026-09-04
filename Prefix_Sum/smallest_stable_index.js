/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var firstStableIndex = function(nums, k) {
    let n = nums.length
    let min = Array(n)
    let mi = 1000000000
    let mx = 0
    for(let i=n-1;i>=0;i--){
        mi = Math.min(mi,nums[i])
        min[i] = mi
    }
    for(let i=0;i<n;i++){
        mx = Math.max(mx,nums[i])
        if(mx-min[i]<=k)return i
    }
    return -1
};