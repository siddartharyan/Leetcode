class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        int M = 1e9+7;
        vector<int>v(n+1,1);
        while(k--){
            for(int i=1;i<n;++i){
                v[i]=(v[i]+v[i-1])%M;
            }
        }
        return v[n-1]%M;
    }
};