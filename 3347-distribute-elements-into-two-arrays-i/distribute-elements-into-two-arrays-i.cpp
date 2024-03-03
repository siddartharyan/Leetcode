class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int>a1,a2;
        int n = nums.size();
        a1.push_back(nums[0]);
        a2.push_back(nums[1]);
        int i=2;
        while(i<n){
            if(a1.back()>a2.back()){
                a1.push_back(nums[i]);
            }else{
                a2.push_back(nums[i]);
            }
            ++i;
        }
        for(auto x:a2) a1.push_back(x);
        return a1;
    }
};