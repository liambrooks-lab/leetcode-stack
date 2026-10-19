/*
{
    "problem_name": "Find Target Indices After Sorting Array",
    "category": "Arrays / Math (Counting)",
    "time_complexity": "O(N) - Single linear pass bypassing standard sorting overhead",
    "space_complexity": "O(1) - Zero extra allocation besides the required return slice"
}
*/

package arrays

func targetIndices(nums []int, target int) []int {
    lessCount := 0
    equalCount := 0
    
    // Step 1: O(N) Linear Scan
    // CPU L1 cache loves contiguous array scans without mutation!
    for _, num := range nums {
        if num < target {
            lessCount++
        } else if num == target {
            equalCount++
        }
    }
    
    // Step 2: Pre-allocate the exact slice size to avoid dynamic resizing bottlenecks
    res := make([]int, equalCount)
    
    // Step 3: Populate the perfectly calculated indices
    for i := 0; i < equalCount; i++ {
        res[i] = lessCount + i
    }
    
    return res
}