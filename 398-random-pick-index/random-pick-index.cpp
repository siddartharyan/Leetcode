class Solution {
public:
    unordered_map<int,vector<int>>mp;
    unordered_map<int,int>mp1;
    Solution(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;++i) mp[nums[i]].push_back(i);
    }
    
    int pick(int target) {
        vector<int>v=mp[target];
        int i = mp1[target]%v.size();
        ++mp1[target];
        return v[i];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */