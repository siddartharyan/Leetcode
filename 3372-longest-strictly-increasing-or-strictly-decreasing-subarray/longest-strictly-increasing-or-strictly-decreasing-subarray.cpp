class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 1;
        int n = nums.size();
        int cnt = 1;
        for(int i=1;i<n;++i){
            if(nums[i-1]<nums[i]) ++cnt;
            else{
                ans=max(ans,cnt);
                cnt=1;
            }
        }
        ans=max(ans,cnt);
        cnt = 1;
        for(int i=1;i<n;++i){
            if(nums[i-1]>nums[i]) ++cnt;
            else{
                ans=max(ans,cnt);
                cnt=1;
            }
        }
        ans=max(ans,cnt);
        return ans;
    }
};