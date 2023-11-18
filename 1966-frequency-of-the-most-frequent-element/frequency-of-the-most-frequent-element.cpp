class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans = 0;
        int left=0;
        long sum=0,current=0;
        for(int right=0;right<nums.size();++right){
            current=nums[right];
            sum+=nums[right];
            while((right-left+1)*current - sum > k){
                sum-=nums[left];
                ++left;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};