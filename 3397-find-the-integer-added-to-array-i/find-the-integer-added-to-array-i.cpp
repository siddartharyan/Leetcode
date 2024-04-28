class Solution {
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {
        int m1=INT_MAX,m2=INT_MAX;
        for(auto &x:nums1) m1=min(m1,x);
        for(auto &x:nums2) m2=min(m2,x);
        return m2-m1;
    }
};