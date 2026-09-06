/**
 * @param {string} s
 * @param {string} t
 * @return {number}
 */
var numDistinct = function(s, t) {
    const m = s.length;
    const n = t.length;
    if (m < n) return 0;
    
    // V8 Engine Optimization: 1D Int32Array for O(N) space and zero heap fragmentation
    const dp = new Int32Array(n + 1);
    dp[0] = 1; // Base case: an empty string 't' is always formed 1 way
    
    for (let i = 1; i <= m; i++) {
        for (let j = n; j >= 1; j--) {
            if (s[i - 1] === t[j - 1]) {
                dp[j] = (dp[j] + dp[j - 1]) | 0; // Bitwise OR to force 32-bit signed integer wrapping
            }
        }
    }
    
    return dp[n];
};