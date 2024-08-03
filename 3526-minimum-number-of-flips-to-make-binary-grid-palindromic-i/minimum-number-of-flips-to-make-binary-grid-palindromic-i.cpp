class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int m = grid.size(),n=grid[0].size();
        int ans1 = 0, ans2 = 0;
        int i=0;
        while(i<m){
            int j1=0,j2=n-1;
            while(j1<j2){
                if(grid[i][j1] != grid[i][j2]) ++ans1;
                ++j1;
                --j2;
            }
            ++i;
        }
        i=0;
        while(i<n){
            int j1=0,j2=m-1;
            while(j1<j2){
                if(grid[j1][i] != grid[j2][i]) ++ans2;
                ++j1;
                --j2;
            }
            ++i;
        }
        return min(ans1,ans2);
    }
};