class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>p;
        int M = 1e9+7;
        long long ans = 1;
        for(auto &x:nums) p.push(x);
        while(k>0){
            int l = p.top();
            p.pop();
            --k;
            ++l;
            p.push(l);
        }
        while(!p.empty()){
            ans =(ans*p.top())%M;
            p.pop();
        }
        return ans;
    }
};