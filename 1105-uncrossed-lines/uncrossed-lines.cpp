class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<int>&nums1,vector<int>&nums2,int i,int j,int &n,int &m){
        if(i==n || j==m) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int x = 0;
        if(nums1[i] == nums2[j]) x = 1+solve(nums1,nums2,i+1,j+1,n,m);
        else x = max(solve(nums1,nums2,i+1,j,n,m),solve(nums1,nums2,i,j+1,n,m));
        return dp[i][j] = x;
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        dp.resize(n+1,vector<int>(m+1,-1));
        return solve(nums1,nums2,0,0,n,m);
    }
};