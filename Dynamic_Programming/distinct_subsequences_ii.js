/**
 * @param {string} s
 * @return {number}
 */
var distinctSubseqII = function(s) {
  const MOD = 1e9 + 7;
  
  // Tracks the most recent index where each lowercase English letter appeared (-1 if never seen)
  const lastOccurrence = new Array(26).fill(-1);
  
  // dp[i] stores the total number of distinct subsequences formed using the prefix of length i
  const dp = new Array(s.length + 1).fill(0);
  
  // Base case: exactly 1 distinct subsequence (the empty string) for a prefix of length 0
  dp[0] = 1;

  for (let i = 0; i < s.length; i++) {
    const charIndex = s.charCodeAt(i) - 97;
    
    // Core transition: adding the current character doubles the total distinct subsequences formed so far
    dp[i + 1] = (dp[i] * 2) % MOD;
    
    // If the current character has appeared previously, subtract the redundant duplicates
    if (lastOccurrence[charIndex] !== -1) {
      dp[i + 1] = (dp[i + 1] - dp[lastOccurrence[charIndex]] + MOD) % MOD;
    }
    
    // Update the last seen index tracker for the current character to its current position
    lastOccurrence[charIndex] = i;
  }

  // Subtract 1 from the final state to exclude the empty subsequence, fulfilling the non-empty requirement
  return (dp[s.length] - 1 + MOD) % MOD;
};