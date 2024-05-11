class Solution {
public:
    bool check(vector<int>&v){
        int f = -1;
        for(int i=0;i<26;++i){
            if(v[i] == 0) continue;
            if(f == -1) f=v[i];
            else if(f != v[i]) return false;
        }
        return true;
    }
    int dp[1001];
    int solve(int i,int &n,string &s){
        if(i == n) return 0;
        if(dp[i] != -1) return dp[i];
        int ans = n;
        vector<int>v(26);
        for(int j=i;j<n;++j){
            ++v[s[j]-'a'];
            if(check(v)){
                ans=min(ans,1+solve(j+1,n,s));
            }
        }
        return dp[i]=ans;
    }
    int minimumSubstringsInPartition(string s) {
        int n = s.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,n,s);
    }
};