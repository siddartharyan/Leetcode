class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int k = 0;
        for(int i=0;i<n;++i){
            k = nums[i]%3;
            ans += min(k,3-k);
        }
        return ans;
    }
};