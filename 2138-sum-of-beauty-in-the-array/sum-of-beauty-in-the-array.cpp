class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size();
        vector<int>v=nums;
        for(int i=n-2;i>=0;--i) v[i]=min(v[i],v[i+1]);
        int ans = 0;
        int k = nums[0];
        for(int i=1;i<n-1;++i){
            if(nums[i] > k && v[i+1] > nums[i]) ans += 2;
            else if((nums[i] > nums[i-1]) && (nums[i+1] > nums[i])) ++ans;
            k=max(k,nums[i]);
        }
        return ans;
    }
};