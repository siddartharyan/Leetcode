class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        double ans = DBL_MAX;
        sort(nums.begin(),nums.end());
        double t = 0;
        int i=0,j=nums.size()-1;
        while(i<j){
            t = ((nums[i]+nums[j]) * (1.0000))/2;
            ans = min(ans,t);
            ++i,--j;
        }
        return ans;
    }
};