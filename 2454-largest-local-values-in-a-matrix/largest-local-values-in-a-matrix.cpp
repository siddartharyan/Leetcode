class Solution {
public:
    int solve(vector<vector<int>>&g,int &i,int &j,int &n){
        int ans = -1;
        for(int k1 =i;k1<i+3;++k1){
            for(int k2=j;k2<j+3;++k2){
                ans=max(ans,g[k1][k2]);
            }
        }
        return ans;
    }
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>>ans(n-2,vector<int>(n-2));
        int k1 = 0,k2 = 0;
        for(int i=0;i<n;++i){
            k2 = 0;
            for(int j=0;j<n;++j){
                if(i+3<=n && j+3<=n){
                    ans[k1][k2] = solve(grid,i,j,n);
                    ++k2; 
                }else{
                    break;
                }
            }
            ++k1;
        }
        return ans;
    }
};