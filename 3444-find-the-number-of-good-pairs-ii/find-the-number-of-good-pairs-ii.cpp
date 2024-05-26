class Solution {
public:
    typedef long long ll;
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        ll ans = 0;
        unordered_map<ll,ll>mp1;
        for(auto &x:nums2) ++mp1[k*x];
        int l = 0;
        for(auto &x:nums1){
            l = sqrt(x);
            for(int i=1;i<=l;++i){
                if(x%i != 0) continue;
                ans +=mp1[i];
                if(x/i != i) ans += mp1[x/i];
            }
        }
        return ans;
    }
};