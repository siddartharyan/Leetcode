class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long,vector<long long>,greater<long long>>p;
        int n = nums.size();
        for(auto x:nums) p.push(x);
        int ans = 0;
        while(!p.empty() and p.size()>=2 and p.top()<k){
            long long x = p.top();
            p.pop();
            long long y = p.top();
            p.pop();
            p.push((long long)(2*min(x,y)+max(x,y)));
            ++ans;
        }
        return ans;
    }
};