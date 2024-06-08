class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(k+1,0));
        unordered_map<int,int>mp;
        vector<int>ans(k+1,0);
        dp[0][0]=1;
        mp[nums[0]]=0;
        ans[0]=1;
        int m = 0;
        int finalAns=1;
        for(int i=1;i<n;++i){
            dp[i][0]=1;
            m=min(i,k);
            if(mp.find(nums[i]) != mp.end()){
                for(int j=0;j<=m;++j){
                    dp[i][j]=max(dp[i][j],dp[mp[nums[i]]][j]+1);
                }
            }
            mp[nums[i]]=i;
            for(int j=0;j<=m && j<k;++j){
                dp[i][j+1]=max(dp[i][j+1],ans[j]+1);
            }
            for(int j=0;j<=m;++j){
                ans[j]=max(ans[j],dp[i][j]);
            }
        }
        for(int i=0;i<=k;++i) finalAns=max(finalAns,ans[i]);
        return finalAns;
    }
};