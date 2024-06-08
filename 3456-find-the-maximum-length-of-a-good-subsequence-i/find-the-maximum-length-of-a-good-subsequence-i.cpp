class Solution {
public:
    int dp[501][501][26];
    int solve(int i,int p,int &n,vector<int>&nums,int k){
        if(i==n) return 0;
        if(dp[i][p+1][k] != -1){
            return dp[i][p+1][k];
        }
        int ans = -1;
        if(p == -1){
            ans=max(ans,solve(i+1,-1,n,nums,k));
            ans=max(ans,1+solve(i+1,i,n,nums,k));
        }else{
            if(nums[p] == nums[i]){
                ans=max(ans,solve(i+1,p,n,nums,k));
                ans=max(ans,1+solve(i+1,i,n,nums,k));
            }else{
                ans=max(ans,solve(i+1,p,n,nums,k));
                if(k>0){
                    ans=max(ans,1+solve(i+1,i,n,nums,k-1));
                }
            }
        }
        return dp[i][p+1][k]=ans;
    }
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,-1,n,nums,k);
    }
};