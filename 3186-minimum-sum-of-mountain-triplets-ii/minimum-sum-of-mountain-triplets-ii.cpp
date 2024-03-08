class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int ans = INT_MAX;
        int n = nums.size();
        vector<int>v=nums;
        for(int i=n-2;i>=0;--i){
            v[i]=min(v[i],v[i+1]);
        }
        int sm = nums[0];
        for(int i=1;i<n-1;++i){
            if(nums[i] > sm && nums[i] > v[i+1]){
                ans=min(ans,sm+nums[i]+v[i+1]);
            }
            sm=min(sm,nums[i]);
        }
        return ans == INT_MAX ? -1 :ans;
    }
};