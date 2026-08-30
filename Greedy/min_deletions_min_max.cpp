class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minv=nums[0];
        int maxv=nums[0];
        int mini=0;
        int maxi=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<minv){
                minv=nums[i];
                mini=i;
            }
            if(nums[i]>maxv){
                maxv=nums[i];
                maxi=i;
            }
        }
        int l=min(mini,maxi);
        int r=max(mini,maxi);
        // cout << l <<" " << r << endl;

        return min({l+r-l+1,n-1-r+l+2,r-l+n-1-r+1});
    }
};