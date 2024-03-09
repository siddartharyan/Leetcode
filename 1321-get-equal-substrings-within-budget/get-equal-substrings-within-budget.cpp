class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int ans = 0;
        int val = maxCost;
        int j=0;
        int n = s.size();
        for(int i=0;i<n;++i){
            val -= abs(s[i]-t[i]);
            if(val<0){
                val += abs(s[j]-t[j]);
                ++j;
            }
            ans=max(ans,i-j+1);
        }
        return ans;
    }
};