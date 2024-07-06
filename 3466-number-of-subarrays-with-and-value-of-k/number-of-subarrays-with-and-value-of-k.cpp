class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans = 0;
        unordered_map<int,int>mp1;
        for(auto &x:nums){
            unordered_map<int,int>mp;
            ++mp[x];
            for(auto &y:mp1){
                mp[y.first & x] += y.second;
            }
            ans += mp[k];
            mp1=mp; 
        }
        return ans;
    }
};