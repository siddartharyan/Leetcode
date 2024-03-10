class Solution {
public:
    long long maximumHappinessSum(vector<int>& h, int k) {
        long long ans = 0;
        int n = h.size();
        sort(h.begin(),h.end(),greater<int>());
        int l = 0;
        while(k--){
            if(h[l]-l<=0) break;
            ans += (h[l]-l);
            ++l;
        }
        return ans;
    }
};