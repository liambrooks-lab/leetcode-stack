class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        
        // Phase 1: Total sum is equivalent to the prefix sum of the entire array (prefix[n-1])
        int current_sum = 0;
        for (int x : stones) {
            current_sum += x;
        }
        
        // Base case: If the player is forced to take all stones, they get current_sum
        int max_diff = current_sum; 
        
        // Phase 2: State-Space folding from right to left
        // We stop at i = 2 (which represents choosing 2 stones, the minimum allowed)
        for (int i = n - 1; i >= 2; --i) {
            // Remove the current stone to simulate moving backwards in the prefix array
            current_sum -= stones[i];
            
            // The optimal decision: Take this prefix sum MINUS the opponent's best future move,
            // OR skip this prefix sum and keep the current max_diff
            if (current_sum - max_diff > max_diff) {
                max_diff = current_sum - max_diff;
            }
        }
        
        return max_diff;
    }
};