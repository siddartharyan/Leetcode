class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& hc, vector<int>& vc) {
        long long ans = 0;
        m = hc.size(),n=vc.size();
        sort(hc.begin(),hc.end(),greater<int>());
        sort(vc.begin(),vc.end(),greater<int>());
        int i=0,j=0;
        while(i<m && j<n){
            if(hc[i] > vc[j]){
                ans += (hc[i] * (long long)(j+1));
                ++i;
            }else{
                ans += (vc[j] * (long long)(i+1));
                ++j;
            }
        }
        while(i<m){ans += (hc[i++] * (long long)(j+1));};
        while(j<n){ans += (vc[j++] * (long long)(i+1));};
        return ans;
    }
};