class Solution {
public:
    vector<long long>dp;
    long long solve(vector<pair<int,int>>&v,int i,int &n){
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        long long ans = solve(v,i+1,n);
        int j=i+1;
        while(j<n && v[j].first<v[i].first+3){
            ++j;
        }
        ans = max(ans,(long long)v[i].first*(long long)v[i].second
        + solve(v,j,n));
        return dp[i]=ans;
    }
    long long maximumTotalDamage(vector<int>& power) {
        map<int,int>mp;
        int n = power.size();
        for(auto &x:power) ++mp[x];
        vector<pair<int,int>>v;
        for(auto &x:mp) v.push_back(x);
        n=v.size();
        dp.resize(n,-1);
        return solve(v,0,n);
    }
};