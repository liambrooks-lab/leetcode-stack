class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int current_end = 0;
        int farthest = 0;
        
        // Loop stops right before the last index
        for (int i = 0; i < nums.size() - 1; i++) {
            // Keep track of the maximum distance we can reach
            farthest = max(farthest, i + nums[i]);
            
            // If we hit the boundary of our current jump
            if (i == current_end) {
                jumps++;
                current_end = farthest;
            }
        }
        
        return jumps;
    }
};