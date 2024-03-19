class Solution {
public:
    int M =1000000007;
    unordered_map<int,unordered_map<int,int>>dp;
    int solve(int s,int e,int k){
        if(k==0 && s==e) return 1;
        if(k==0) return 0;
        if(dp[s].count(k)) return dp[s][k];
        int f = solve(s-1,e,k-1)%M;
        int se = solve(s+1,e,k-1)%M;
        return dp[s][k]=(f+se)%M;
    }
    int numberOfWays(int s, int e, int k) {
        return solve(s,e,k);
    }
};