class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int ans = 0;
        vector<vector<int>>dp=grid;
        int n=grid.size(),m=grid[0].size();
        if(grid[0][0] > k) return 0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(i>=1) dp[i][j]+=dp[i-1][j];
                if(j>=1) dp[i][j]+=dp[i][j-1];
                if(i>=1 and j>=1) dp[i][j]-=dp[i-1][j-1];
                if(dp[i][j] <= k) ++ans;
            }
        }
        return ans;
    }
};