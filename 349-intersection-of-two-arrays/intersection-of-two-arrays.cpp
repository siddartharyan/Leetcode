class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        vector<int>d(1001);
        for(auto &x:nums1) ++d[x];
        for(auto &x:nums2){
            if(d[x] != 0){
                ans.push_back(x);
                d[x]=0;
            }
        }
        return ans;
    }
};