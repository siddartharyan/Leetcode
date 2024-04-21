class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int>l(26);
        vector<int>u(26);
        int n = word.size();
        int ans = 0;
        char c = '0';
        for(int i=0;i<n;++i){
            c = word[i];
            if(c>='a' && c<='z') ++l[c-'a'];
            else if(c>='A' && c<='Z') ++u[c-'A'];
        }
        for(int i=0;i<26;++i){
            if(l[i] > 0 && u[i] > 0) ++ans;
        }
        return ans;
    }
};