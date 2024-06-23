class Solution {
public:
    typedef long long ll;
    ll dp[100005][2][2];
    ll solve(int p,int s,int si,vector<ll>&a){
        if(p == a.size()) return 0;
        ll ans = LONG_MIN;
        if(dp[p][s][si] != -1) return dp[p][s][si];
        if(s == 0){
            ans = max(ans,a[p]+solve(p+1,1,1,a));
        }
        else{
            if(si == 1){
                ans = max(ans,-a[p]+solve(p+1,1,0,a));
                ans = max(ans,solve(p,0,0,a));
            }else{
                ans = max(ans,a[p]+solve(p+1,1,1,a));
                ans = max(ans,solve(p,0,0,a));
            }
        }
        return dp[p][s][si]=ans;
    }
    long long maximumTotalCost(vector<int>& nums) {
        int n = nums.size();
        vector<ll>a(nums.begin(),nums.end());
        memset(dp,-1,sizeof(dp));
        return solve(0,0,0,a);
    }
};