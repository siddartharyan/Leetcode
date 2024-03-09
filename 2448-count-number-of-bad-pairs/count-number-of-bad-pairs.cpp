class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        //j-i != nums[j]-nums[i]
        //j-nums[j] != -nums[i]+i
        //nums[j]-j != nums[i]-i
        unordered_map<long long,long long>mp;
        int n = nums.size();
        long long ans = 0;
        for(int i=n-1;i>=0;--i){
            long long k = nums[i]-i;
            ans += mp[k];
            ++mp[k];
        }
        long long f = ((long long)(n-1)*(long long)n)/2;
        return f-ans;
    }
};