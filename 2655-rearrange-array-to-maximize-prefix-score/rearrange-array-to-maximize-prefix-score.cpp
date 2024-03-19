class Solution {
public:
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end(),greater<int>());
        long long int ans = 0;
        int c = 0;
        for(int i=0;i<n;++i){
            ans += nums[i];
            if(ans<=0) break;
            ++c;
        }
        return c;
    }
};