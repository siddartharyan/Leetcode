class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int>v;
        int MOD = 1e9+7;
        for(int i=0;i<n;++i){
            v.push_back(nums[i]);
            int s = nums[i];
            for(int j=i+1;j<n;++j){
                s += nums[j];
                v.push_back(s);
            }
        }
        sort(v.begin(),v.end());
        int ans = 0;
        for(int k=left-1;k<right;++k){
            ans = (ans+v[k])%MOD;
        }
        return ans;
    }
};