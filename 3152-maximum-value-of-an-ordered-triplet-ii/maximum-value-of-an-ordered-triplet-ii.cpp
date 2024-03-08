class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        vector<int>v=nums;
        for(int i=n-2;i>=0;--i) v[i]=max(v[i],v[i+1]);
        int k=nums[0];
        for(int i=1;i<n-1;++i){
            ans=max(ans,(long long)(k-nums[i])*v[i+1]);
            k=max(k,nums[i]);
        }
        return ans<0?0:ans;
    }
};