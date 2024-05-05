class Solution {
public:
    bool solve(string &s,int &n,int &k){
        vector<int>v(26,0);
        for(int i=0;i<k;++i) ++v[s[i]-'a'];
        for(int i=k;i<n;i+=k){
            vector<int>v1(26);
            for(int j=i;j<i+k;++j) ++v1[s[j]-'a'];
            for(int j=0;j<26;++j){
                if(v1[j] != v[j]) return false;
            }
        }
        return true;
    }
    int minAnagramLength(string s) {
        int n = s.size();
        int m = INT_MAX;
        for(int i=1;i<=n;++i){
            if(n%i==0 && solve(s,n,i)){
                m=i;
                break;
            }
        }
        return m;
    }
};