class Solution {
public:
    bool solve(string s,int li){
        int n = s.size();
        vector<int>lp(n+1,0);
        int p = 0;
        for(int i=1;i<n;++i){
            p=lp[i-1];
            while(p>0 && s[i] != s[p]){
                p=lp[p-1];
            }
            lp[i]=p+(s[i] == s[p] ? 1 : 0);
            if(lp[i]==li) return true;
        }
        return false;
    }
    string binary(int n){
        string s ="";
        int re = 0;
        while(n>0){
            re = n%2;
            if(re == 1) s.push_back('1');
            else s.push_back('0');
            n/=2;
        }
        reverse(s.begin(),s.end());
        return s;
    }
    bool queryString(string s, int n) {
        string s1 = "";
        int k = binary(n).size();
        if(k > s.size()) return false;
        for(int i=1;i<=n;++i){
            s1 = binary(i);
            if(!solve(s1+'#'+s,s1.size())){
                return false;
            }
        }
        return true;
    }
};