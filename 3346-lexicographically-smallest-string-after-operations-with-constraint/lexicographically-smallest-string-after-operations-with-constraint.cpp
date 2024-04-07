class Solution {
public:
    string getSmallestString(string s, int k) {
        string ans = s;
        int n = s.size();
        int l = 0;
        for(int i=0;i<n && k>0;++i){
            l = min(s[i]-'a','z'-s[i]+1);
            ans[i]=(l<=k?'a':s[i]-k);
            k-=l;
        }
        return ans;
    }
};