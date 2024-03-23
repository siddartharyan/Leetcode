class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int ans = 0,j = 0;
        int n = s.size();
        int cnt = 0;
        for(int i=0;i<n-1;++i){
            if(s[i] == s[i+1]) ++cnt;
            while(j<i && cnt > 1){
                if(s[j] == s[j+1]) --cnt;
                ++j;
            }
            ans = max(ans,i-j+1);
        }
        return ans+1;
    }
};