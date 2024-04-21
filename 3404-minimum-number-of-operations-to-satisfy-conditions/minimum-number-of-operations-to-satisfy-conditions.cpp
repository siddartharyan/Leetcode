class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<vector<int>>&g,int k,int j,int &m,int &n){
        if(j>=m) return 0;
        if(dp[j][k] != -1) return dp[j][k];
        int c = 0, mi=INT_MAX;
        for(int i=0;i<n;++i){
            c += (g[i][j] != k);
        }
        for(int l=0;l<10;++l){
            if(l == k) continue;
            mi=min(mi,c+solve(g,l,j+1,m,n));
        }
        return dp[j][k]=mi;
    }
    int minimumOperations(vector<vector<int>>& grid) {
        int n = grid.size(),m=grid[0].size();
        int ans = INT_MAX;
        dp.resize(m+1,vector<int>(10,-1));
        for(int i=0;i<10;++i){
            ans=min(ans,solve(grid,i,0,m,n));
        }
        return ans;
    }
};