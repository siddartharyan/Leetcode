class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int ans = INT_MIN;
        int n = energy.size();
        vector<int>d=energy;
        int v = 0;
        for(int i=k;i<n;++i){
            v=d[i]+d[i-k];
            if(v>d[i]){
                d[i]=v;
            }
        }
        for(int i=n-1;i>=n-k;--i){
            ans=max(ans,d[i]);
        }
        return ans;
    }
};