class Solution {
public:
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        unordered_map<int,int>mp;
        for(auto &x:nums2){
            ++mp[x*k];
        }
        int ans = 0;
        for(auto &x:nums1){
            for(auto &y:mp){
                if(x%y.first == 0) ans += y.second;
            }
        }
        return ans;
    }
};