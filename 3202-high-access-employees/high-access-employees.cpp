class Solution {
public:
    int atoi(const string &s){
        int ans = 0;
        for(auto &x:s){
            ans *= 10;
            ans += (x-'0');
        }
        return ans;
    }
    int get(string &a){
        int h = atoi(a.substr(0,2));
        int m = atoi(a.substr(2,2));
        return h*60+m;
    }
    vector<string> findHighAccessEmployees(vector<vector<string>>& a) {
        unordered_map<string,vector<int>>mp;
        for(auto &x:a){
            mp[x[0]].push_back(get(x[1]));
        }
        for(auto &x:mp){
            sort(x.second.begin(),x.second.end());
        }
        vector<string>ans;
        for(auto &x:mp){
            vector<int>t = x.second;
            bool f = false;
            int n = t.size();
            for(int i=0;i<n;++i){
                int start = t[i];
                int end = start + 60;
                int c = 1;
                for(int j=i+1;j<n;++j){
                    if(t[j]<end) ++c;
                    else break;
                    if(c>=3) break;
                }
                if(c>=3){
                    f=true;
                    break;
                }
            }
            if(f) ans.push_back(x.first);
        }
        return ans;
    }
};