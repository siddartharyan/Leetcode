class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1);
        int ans = 0;
        for(int i=0;i<n;++i){
            int k = 0;
            for(int j=0;j<i;++j){
                if(nums[i] >= nums[j]){
                    k=max(k,dp[j]);
                }
            }
            dp[i]=k+1;
            ans=max(dp[i],ans);
        }
        return n - ans;
    }
};