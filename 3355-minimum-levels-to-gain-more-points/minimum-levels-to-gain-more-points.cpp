class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int n = possible.size();
        vector<int>suff(n);
        for(int i=0;i<n;++i) if(possible[i] == 0) possible[i]=-1;
        suff[n-1]=possible[n-1];
        for(int i=n-2;i>=0;--i) suff[i]=suff[i+1]+possible[i];
        int ans = INT_MAX;
        int sum = 0;
        for(int i=0;i<n-1;++i){
            sum += possible[i];
            if(sum > suff[i+1]){
                ans=i+1;
                break;
            }
        }
        return ans == INT_MAX?-1:ans;
    }
};