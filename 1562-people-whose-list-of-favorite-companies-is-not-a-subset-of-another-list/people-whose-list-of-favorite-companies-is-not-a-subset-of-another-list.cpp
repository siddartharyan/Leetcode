class Solution {
public:
    bool isSubset(vector<string>&a,vector<string>&b){
        int n = a.size();
        int m = b.size();
        if(n > m) return false;
        int c = 0;
        int i=0,j=0;
        while(i<n && j<m){
            if(a[i] == b[j]){
                ++c;
                ++i;++j;
            }else{
                ++j;
            }
        }
        return c == n;
    }
    vector<int> peopleIndexes(vector<vector<string>>& f) {
        vector<int>ans;
        int n = f.size();
        for(int i=0;i<n;++i){
            sort(f[i].begin(),f[i].end());
        }
        for(int i=0;i<n;++i){
            bool f1=true;
            for(int j=0;j<n;++j){
                if(i==j) continue;
                bool f2 = isSubset(f[i],f[j]);
                if(f2){
                    f1=false;
                    break;
                }
            }
            if(f1) ans.push_back(i);
        }
        return ans;
    }
};