class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ans=0;
        for(int i=0;i<n;++i){
            if(i+2<n && (nums[i] == 0)){
                nums[i]=!nums[i];
                nums[i+1]=!nums[i+1];
                nums[i+2]=!nums[i+2];
                ++ans;
            }
        }
        for(int i=0;i<n;++i) if(nums[i] != 1) return -1;
        return ans;
    }
};