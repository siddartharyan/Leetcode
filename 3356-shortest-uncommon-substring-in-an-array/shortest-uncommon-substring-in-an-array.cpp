class Solution {
public:
    unordered_set<string> getSubstr(string &s){
        unordered_set<string>v;
        string k = "";
        for(int i=0;i<s.size();++i){
            k=s[i];
            v.insert(k);
            for(int j=i+1;j<s.size();++j){
                k+=s[j];
                v.insert(k);
            }
        }
        return v;
    }
    vector<string> shortestSubstrings(vector<string>& arr) {
        vector<string>ans;
        vector<unordered_set<string>>v;
        for(auto &x:arr){
            v.push_back(getSubstr(x));
        }
        int n = v.size();
        for(int i=0;i<n;++i){
            unordered_set<string>first=v[i];
            string k = "";
            for(auto &x:first){
                bool f = true;
                for(int j=0;j<n;++j){
                   if(i==j) continue;
                   if(v[j].find(x) != v[j].end()){
                       f=false;
                       break;
                   }
                }
                if(f){
                    if(k=="") k=x;
                    else{
                        if(k.size()>x.size()) k= x;
                        else if(k.size()==x.size()) k=min(k,x);
                    }
                }
            }
            ans.push_back(k);
        }
        return ans;
    }
};