class Solution {
public:
    bool isCapital(char &c){
        return c>='A' && c<='Z';
    }
    vector<string>split(string &s){
        vector<string>ans;
        string s1 = "";
        int n = s.size();
        for(int i=0;i<n;++i){
            if(s1 != ""){
                if(isCapital(s[i])) {
                    if(isCapital(s1[0])) ans.push_back(s1);
                    s1="";
                }
            }
            s1 += s[i];
        }
        if(s1 != "" && isCapital(s1[0])) ans.push_back(s1);
        return ans;
    }
    bool isMatch(string &s,string &p){
        int n = s.size();
        int m = p.size();
        if(m > n) return false;
        int i =0,j=0;
        int cnt = 0;
        while(i<n && j<m){
            if(s[i] == p[j]){
                ++cnt;
                ++i;
                ++j;
            }else{
                ++i;
            }
        }
        return cnt == m;
    }
    int min(int m,int n){
        return m > n ? n : m;
    }
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool>ans;
        vector<string>p=split(pattern);
        int n = p.size();
        if(n==0){
            for(auto x:queries) ans.push_back(isMatch(x,pattern));
            return ans;
        }
        for(auto x:queries){
            vector<string>t = split(x);
            int cnt = 0;
            if(t.size() != n){
                ans.push_back(false);
                continue;
            }
            for(int i=0;i<n;++i){
                if(isMatch(t[i],p[i])){
                    ++cnt;
                }
            }
            ans.push_back(cnt == n);
        }
        return ans;
    }
};