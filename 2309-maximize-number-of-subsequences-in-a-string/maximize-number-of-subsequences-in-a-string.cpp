class Solution {
public:
    long long solve(const string &s,const string &p){
        vector<int>v1,v2;
        char c = '0';
        for(int i=0;i<s.size();++i){
            c = s[i];
            if(c == p[0]) v1.push_back(i);
            else if(c == p[1]) v2.push_back(i);
        }
        long long ans = 0;
        long long n=v1.size(),m=v2.size();
        if(p[0] == p[1]){
            return (n*(n-1))/2;
        }
        for(int i=0,j=0;i<n;++i){
            while(j < m && v1[i] > v2[j]) ++j;
            ans += (m-j);
        }
        return ans;
    }
    long long maximumSubsequenceCount(string t, string p) {
        string p1 = p[0]+t;
        string p2 = t+p[1];
        return max(solve(p1,p),solve(p2,p));
    }
};