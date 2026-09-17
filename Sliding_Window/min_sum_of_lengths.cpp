/*
{
    "problem_name": "Find Two Non-overlapping Sub-arrays Each With Target Sum",
    "category": "Sliding Window",
    "time_complexity": "O(N)",
    "space_complexity": "O(N)"
}
*/

#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        // dp array to track the minimum length of a valid subarray ending at or before index i
        vector<int> best(n, INT_MAX); 
        
        int current_sum = 0;
        int left = 0;
        int ans = INT_MAX;
        int min_len_so_far = INT_MAX;
        
        for (int right = 0; right < n; ++right) {
            current_sum += arr[right];
            
            // State-space pruning: Shrink window if sum exceeds target
            while (current_sum > target && left <= right) {
                current_sum -= arr[left];
                left++;
            }
            
            // Target locked
            if (current_sum == target) {
                int curr_len = right - left + 1;
                
                // Check if we have a valid non-overlapping subarray ending before our 'left' pointer
                if (left > 0 && best[left - 1] != INT_MAX) {
                    ans = min(ans, curr_len + best[left - 1]);
                }
                
                // Update the minimum length found so far
                min_len_so_far = min(min_len_so_far, curr_len);
            }
            
            // Carry forward the best minimum length up to the current right index
            best[right] = min_len_so_far;
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};