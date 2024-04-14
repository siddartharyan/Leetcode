typedef long long ll; 
class Solution {
public:
    ll getCnt(vector<int>&coins,ll &mid){
        int n = coins.size();
        ll v = (1<<n)-1;
        ll cnt = 0;
        for(ll mask=1;mask<=v;++mask){
            ll l=1;
            for(int i=0;i<n;++i){
                if(mask & (1<<i)){
                    l=lcm(l,coins[i]);
                }
            }
            if(__builtin_popcount(mask) & 1){
                cnt += (mid/l);
            }else{
                cnt -= (mid/l);
            }
        }
        return cnt;
    }
    long long findKthSmallest(vector<int>& coins, int k) {
        ll l=1,r=1e11;
        ll ans = 0;
        while(l<=r){
            ll mid = l+(r-l)/2;
            ll cnt = getCnt(coins,mid);
            if(cnt >= k){
                ans = mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};