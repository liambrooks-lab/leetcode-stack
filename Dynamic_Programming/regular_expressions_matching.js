/*
{
  "problem_name": "Regular Expressions Matching",
  "category": "Dynamic_Programming",
  "time_complexity": "O(N^2)",
  "space_complexity": "O(N)"
}
*/
/**
 * @param {string} s
 * @param {string} p
 * @return {boolean}
 */
var isMatch = function(s, p) {
    const m = s.length;
    const n = p.length;
    
    // Using Typed Arrays for bare-metal memory optimization
    let dp = new Uint8Array(n + 1);
    
    // Base Case
    dp[0] = 1; 
    
    // Handle empty string matching with patterns like "a*b*"
    for (let j = 1; j <= n; j++) {
        if (p[j - 1] === '*') {
            dp[j] = dp[j - 2];
        }
    }
    
    for (let i = 1; i <= m; i++) {
        let nextDp = new Uint8Array(n + 1);
        for (let j = 1; j <= n; j++) {
            if (p[j - 1] === '*') {
                // 0 occurrences OR (1+ occurrences AND preceding char matches)
                nextDp[j] = nextDp[j - 2] || ((p[j - 2] === s[i - 1] || p[j - 2] === '.') ? dp[j] : 0);
            } else if (p[j - 1] === '.' || p[j - 1] === s[i - 1]) {
                // Exact match or '.' wildcard
                nextDp[j] = dp[j - 1];
            }
        }
        // Move to the next row
        dp = nextDp; 
    }
    
    return dp[n] === 1;
};