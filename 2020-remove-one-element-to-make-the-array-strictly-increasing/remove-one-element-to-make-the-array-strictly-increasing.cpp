class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;++i){
            int val = INT_MIN;
            for(int j=0;j<n;++j){
                if(i==j) continue;
                if(nums[j] > val){
                    val=nums[j];
                }else{
                    val=-1;
                    break;
                }
            }
            if(val != -1) return true;
        }
        return false;
    }
};