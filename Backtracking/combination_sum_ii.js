/*
{
  "problem_name": "Combination Sum Ii",
  "category": "Backtracking",
  "time_complexity": "O(2^N)",
  "space_complexity": "O(N)"
}
*/
/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var combinationSum2 = function(candidates, target) {
    // Strict numeric sort for aggressive pruning
    candidates.sort((a, b) => a - b);
    
    const result = [];
    const len = candidates.length; // Cache length to avoid object property lookups
    
    function backtrack(startIdx, currentTarget, currentPath) {
        if (currentTarget === 0) {
            // Bypass JS iterators! Use native C++ backed slice() for instant memory copy
            result.push(currentPath.slice());
            return;
        }
        
        for (let i = startIdx; i < len; i++) {
            const num = candidates[i]; // Cache the array value into a primitive
            
            // PRUNING 1: Break instantly if the number exceeds our target
            if (num > currentTarget) break;
            
            // PRUNING 2: Eliminate duplicate subset branches instantly
            if (i > startIdx && num === candidates[i - 1]) continue;
            
            currentPath.push(num);
            backtrack(i + 1, currentTarget - num, currentPath);
            currentPath.pop();
        }
    }
    
    backtrack(0, target, []);
    return result;
};