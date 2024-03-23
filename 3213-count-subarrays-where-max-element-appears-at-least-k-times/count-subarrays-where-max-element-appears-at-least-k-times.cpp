class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans = 0;
        int m = 0;
        for(auto &x:nums) m = max(m,x);
        int c = 0;
        int j = 0;
        int n = nums.size();
        for(int i=0;i<n;++i){
            if(nums[i] == m) ++c;
            while(c >= k){
                ans += (n-i);
                if(nums[j] == m) --c;
                ++j;
            }
        }
        return ans;
    }
};