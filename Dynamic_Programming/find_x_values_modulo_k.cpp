/*
{
    "problem_name": "Find X-Values of Subarrays Modulo K",
    "category": "Dynamic Programming",
    "time_complexity": "O(N * K)",
    "space_complexity": "O(K)"
}
*/

#include <vector>
#include <cstring> // Required for memset and memcpy

using namespace std;

// Bare-metal static arrays to completely eliminate memory reallocation overhead (Since max k=5)
int freq[5], freq2[5];

class Solution {
public:
    static vector<long long> resultArray(vector<int>& nums, int k) {
        const int n = nums.size();
        
        // O(1) mathematical bypass for k=1: All possible subarrays leave a remainder of 0
        if (k == 1) return {1LL * n * (n + 1) / 2}; 
        
        vector<long long> ans(k, 0);
        
        // Wipe the frequency array memory to absolute zero
        memset(freq, 0, sizeof(int) * k); 
        
        for (int x : nums) {
            const int r = x % k;
            memset(freq2, 0, sizeof(int) * k);
            
            // 1. Start a new subarray natively
            ans[r]++;
            
            // 2. Extend existing valid subarrays from the previous state
            for (int j = 0; j < k; j++) {
                // 1LL prevents 32-bit integer overflow during product calculation
                const int prod = 1LL * j * r % k;
                freq2[prod] += freq[j];
                ans[prod] += freq[j];
            }
            freq2[r]++;
            
            // 3. State transition using ultra-fast memory block copy
            memcpy(freq, freq2, sizeof(int) * k);
        }
        return ans;
    }
};