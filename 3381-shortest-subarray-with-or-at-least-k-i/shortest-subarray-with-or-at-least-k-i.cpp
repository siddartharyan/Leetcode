class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int ans = INT_MAX;
        int n = nums.size();
        int s = 0;
        for(int i=0;i<n;++i){
            s = nums[i];
            if(s >= k){
                ans = 1;
                break;
            }
            for(int j=i+1;j<n;++j){
                s |= nums[j];
                if(s >= k){
                    ans=min(ans,j-i+1);
                }
            }
        }
        return ans == INT_MAX?-1:ans;
    }
};