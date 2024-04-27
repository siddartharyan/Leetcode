class Solution {
public:
    int M = 1e9+7;
    int numberOfStableArrays(int z, int o, int l) {
        vector<vector<vector<int>>>dp;
        dp.resize(z+1,vector<vector<int>>(o+1,vector<int>(2)));
        for(int i=1;i<=min(z,l);++i){
            dp[i][0][0]=1;
        }
        for(int i=1;i<=min(o,l);++i){
            dp[0][i][1]=1;
        }
        for(int i=1;i<=z;++i){
            for(int j=1;j<=o;++j){
                dp[i][j][0] = (dp[i-1][j][0]+dp[i-1][j][1])%M;
                if(i>l){
                    dp[i][j][0]=(dp[i][j][0]+M-dp[i-l-1][j][1])%M;
                }
                dp[i][j][1]=(dp[i][j-1][0]+dp[i][j-1][1])%M;
                if(j>l){
                    dp[i][j][1]=(dp[i][j][1]+M-dp[i][j-l-1][0])%M;
                }
            }
        }
        return (dp[z][o][0]+dp[z][o][1])%M;
    }
};