class Solution {
public:
    vector<vector<int>> solve(const char &c,vector<vector<char>>&g,int &n,int &m){
        vector<vector<int>>ans(n,vector<int>(m));
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j) ans[i][j] = (g[i][j]==c);
        }
        for(int i=0;i<n;++i){
            for(int j=1;j<m;++j){
                ans[i][j] += ans[i][j-1];
            }
        }

        for(int j=0;j<m;++j){
            for(int i=1;i<n;++i) ans[i][j] += ans[i-1][j];
        }
        return ans;
    }
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size(),m=grid[0].size();
        vector<vector<int>>ans1=solve('X',grid,n,m);
        vector<vector<int>>ans2=solve('Y',grid,n,m);
        int ans = 0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(ans1[i][j] > 0 && ans1[i][j] == ans2[i][j]) ++ans;
            }
        }
        return ans;
    }
};