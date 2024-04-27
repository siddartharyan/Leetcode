class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        long long ans = 0;
        int n = grid.size(),m=grid[0].size();
        vector<int>row(n);
        vector<int>col(m);
        int c = 0;
        for(int i=0;i<n;++i){
            c=0;
            for(int j=0;j<m;++j){
                if(grid[i][j] == 1){
                    ++c;
                    ++col[j];
                }
            }
            row[i]=c;
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j] == 1){
                    ans += (row[i]-1)*(col[j]-1);
                }
            }
        }
        return ans;
    }
};