class Solution {
public:
    int maxOperations(string s) {
        int n = s.size();
        int ans = 0;
        int c = 0;
        for(int i=0;i<n-1;++i){
            if(s[i] == '1') ++c;
            if(s[i] == '1' and s[i+1] == '0') ans += c;
        }
        return ans;
    }
};