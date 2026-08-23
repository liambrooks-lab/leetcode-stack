/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var permuteUnique = function(nums) {
    // Step 1: Sort to group duplicates together
    nums.sort((a, b) => a - b);
    
    const result = [];
    const used = new Array(nums.length).fill(false);
    
    const backtrack = (path) => {
        // Base case: path is complete
        if (path.length === nums.length) {
            result.push([...path]);
            return;
        }
        
        for (let i = 0; i < nums.length; i++) {
            // If the element is already active in the current path, skip it
            if (used[i]) continue;
            
            // THE KILL SHOT: State-Space Pruning
            // Skip if it's a duplicate of the previous element AND the previous element was just skipped
            if (i > 0 && nums[i] === nums[i - 1] && !used[i - 1]) {
                continue; 
            }
            
            // Mark as used and dive deeper
            used[i] = true;
            path.push(nums[i]);
            
            backtrack(path);
            
            // Backtrack: Unmark and remove for the next state exploration
            path.pop();
            used[i] = false;
        }
    };
    
    backtrack([]);
    return result;
};