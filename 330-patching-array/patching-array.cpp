class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int s = nums.size();
        int i = 0;
        long long sum = 0, ans = 0;
        while(sum < n){
            if(i<s && nums[i]<=(sum+1)){
                sum += (nums[i]);
                ++i;
            }else{
                sum += (sum+1);
                ++ans;
            }
        }
        return ans;
    }
};