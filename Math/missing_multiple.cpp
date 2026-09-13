/*
{
  "problem_name": "Missing Multiple",
  "category": "Math",
  "time_complexity": "O(N)",
  "space_complexity": "O(1)"
}
*/
#include <vector>
#include <unordered_set>
class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<bool> freq(101,0);

        for(int i=0;i<nums.size();i++)
        freq[nums[i]] = 1;

        int i = k;
        while(i <= 100) {
            if(!freq[i])
            return i;
            i += k;
        }
        return ((100 / k) + 1) * k;
    }
};