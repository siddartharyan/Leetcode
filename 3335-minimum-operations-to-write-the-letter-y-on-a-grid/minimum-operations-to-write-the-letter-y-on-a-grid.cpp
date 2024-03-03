class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        int ans = INT_MAX;
        int m = grid.size();
        int n = grid[0].size();
        int mid = m%2==0?m/2:(m/2+1);
        --mid;
        for(int i=0;i<3;++i){
            vector<vector<int>>d=grid;
            int x1=0,y1=0;
            int op1 = 0;
            //first make y = i
            while(x1 != mid){
                if(d[x1][y1] != i){
                    d[x1][y1]=-(1000*(i+1));
                    ++op1;
                }else{
                    d[x1][y1]=-(1000*(i+1));
                }
                ++x1;
                ++y1;
            }
            x1=0,y1=n-1;
            while(x1 != mid){
                if(d[x1][y1] != i){
                    d[x1][y1]=-(1000*(i+1));
                    ++op1;
                }else{
                    d[x1][y1]=-(1000*(i+1));
                }
                ++x1;
                --y1;
            }
            while(x1<m){
                if(d[x1][y1] != i){
                    ++op1;
                    d[x1][y1]=-(1000*(i+1));
                }else{
                    d[x1][y1]=-(1000*(i+1));
                }
                ++x1;
            }
            for(int j=0;j<3;++j){
                if(i==j) continue;
                // second make rest = j;
                vector<vector<int>>d1=d;
                int op2 = 0;
                for(x1=0;x1<m;++x1){
                    for(y1=0;y1<n;++y1){
                        if(d1[x1][y1] == -(1000*(i+1))) continue;
                        else if(d1[x1][y1] != j){
                            ++op2;
                            d1[x1][y1]=j;
                        }
                    }
                }
                ans = min(ans,op1+op2);
            }
        }
        return ans;
    }
};