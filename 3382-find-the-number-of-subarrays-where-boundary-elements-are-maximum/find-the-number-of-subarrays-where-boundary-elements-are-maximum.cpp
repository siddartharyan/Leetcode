class Solution {
public:
    long long numberOfSubarrays(vector<int>& nums) {
        vector<pair<int,int>>v;
        int n = nums.size();
        long long ans = n;
        pair<int,int>p;
        for(int i=0;i<n;++i){
            while(v.size() and nums[v.back().first]<nums[i]) v.pop_back();
            if(v.size() and nums[v.back().first]==nums[i]){
                p = v.back();
                v.pop_back();
                ans += p.second;
                p.second += 1;
                v.push_back(p);
            }else{
                v.push_back({i,1});
            }
        }
        return ans;
    }
};