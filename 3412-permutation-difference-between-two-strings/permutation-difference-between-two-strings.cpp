class Solution {
public:
    int findPermutationDifference(string s, string t) {
        vector<int>v(26);
        int n = s.size();
        for(int i=0;i<n;++i){
            v[s[i]-'a']=i;
        }
        int ans = 0;
        for(int i=0;i<n;++i){
            ans += abs(v[t[i]-'a']-i);
        }
        return ans;
    }
};