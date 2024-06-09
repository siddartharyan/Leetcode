class Solution {
public:
    int dp[2000][5000];
    int solve(int i,int t,int &n,vector<int>&nums){
        if(i==n) return t;
        if(dp[i][t] != -1) return dp[i][t];
        int ans = -1;
        if(nums[i] > t){
            ans=max(ans,solve(i+1,t,n,nums));
            ans=max(ans,solve(i+1,t+nums[i],n,nums));
        }else{
            ans=max(ans,solve(i+1,t,n,nums));
        }
        return dp[i][t]=ans;
    }
    int maxTotalReward(vector<int>& r) {
        unordered_set<int>s;
        vector<int>nums;
        memset(dp,-1,sizeof(dp));
        for(auto &x:r) s.insert(x);
        for(auto &x:s) nums.push_back(x);
        int n = nums.size();
        sort(nums.begin(),nums.end());
        return solve(0,0,n,nums);
    }
};