class Solution {
public:
    vector<int> solve(const string &s,const int &k){
        int n = s.size();
        vector<int>l(n);
        int p = 0;
        for(int i=1;i<n;++i){
            p=l[i-1];
            while(p>0 && s[i] != s[p]){
                p=l[p-1];
            }
            l[i]=p+(s[i]==s[p]?1:0);
        }
        vector<int>ans;
        for(int i=0;i<n;++i){
            if(l[i] == k) ans.push_back(i-2*k);
        }
        return ans;
    }
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int>v1 = solve(a+':'+s,a.size());
        vector<int>v2 = solve(b+':'+s,b.size());
        int i=0,j=0;
        int n=v1.size(),m=v2.size();
        vector<int>ans;
        for(int i=0,j=0;i<n;++i){
            while(j<m && abs(v1[i]-v2[j]) > k && (v1[i]>v2[j])) ++j;
            if(j<m && abs(v1[i]-v2[j])<=k) ans.push_back(v1[i]);
        }
        return ans;
    }
};