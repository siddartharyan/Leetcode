class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        for(int i=0;i<k;++i){
            vector<int>t(k);
            for(auto &x:nums){
                t[x%k]=max(t[x%k],t[(i+k-x%k)%k]+1);
                ans=max(ans,t[x%k]);
            }
        }
        return ans;
    }
};