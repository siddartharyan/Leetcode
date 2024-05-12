class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int>d(m,INT_MAX);
        int ans = INT_MIN;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(j>0){
                    d[j] = min(d[j],d[j-1]);
                }
                ans=max(ans,grid[i][j]-d[j]);
                d[j]=min(d[j],grid[i][j]);
            }
        }
        return ans;
    }
};