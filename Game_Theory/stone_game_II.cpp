class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        
        // Suffix sum array to store total stones remaining from index i
        vector<int> suffixSum(n, 0);
        suffixSum[n - 1] = piles[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }
        
        // DP table: dp[i][M] -> max stones current player can get from index i with M
        vector<vector<int>> dp(n, vector<int>(n + 1, 0));
        
        return dfs(piles, 0, 1, dp, suffixSum);
    }
    
private:
    int dfs(vector<int>& piles, int i, int M, vector<vector<int>>& dp, vector<int>& suffixSum) {
        int n = piles.size();

        if (i == n) return 0;
       
        if (i + 2 * M >= n) return suffixSum[i]; 
     
        if (dp[i][M] != 0) return dp[i][M];
        
        int minStonesForOpponent = INT_MAX;
        
        // Explore all possible moves from X = 1 to 2*M
        for (int X = 1; X <= 2 * M; X++) {

            int opponentGets = dfs(piles, i + X, max(M, X), dp, suffixSum);
            
     
            minStonesForOpponent = min(minStonesForOpponent, opponentGets);
        }
        
        dp[i][M] = suffixSum[i] - minStonesForOpponent;
        
        return dp[i][M];
    }
};