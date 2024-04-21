class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int>l(26,-1);
        vector<int>u(26,-1);
        int n = word.size();
        char c = '0';
        for(int i=0;i<n;++i){
            c = word[i];
            if(c>='a' && c<='z') l[c-'a']=i;
            else if((c>='A' && c<='Z') && u[c-'A'] == -1){
                u[c-'A']=i;
            }
        }
        int ans = 0;
        for(int i=0;i<26;++i){
            if(l[i] == -1 || u[i] == -1) continue;
            if(u[i] > l[i]) ++ans;
        }
        return ans;
    }
};