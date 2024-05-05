class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        int n = word.size();
        unordered_map<string,int>mp;
        string s = "";
        int m = 0;
        for(int i=0;i<n;i+=k){
            s = word.substr(i,k);
            ++mp[s];
            m=max(m,mp[s]);
        }
        return n/k-m;
    }
};