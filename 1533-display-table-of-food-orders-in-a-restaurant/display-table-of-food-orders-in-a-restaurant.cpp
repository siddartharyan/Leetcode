class Solution {
public:
    int get(string &s){
        int ans = 0;
        for(auto &x:s){
            ans *= 10;
            ans += (x-'0');
        }
        return ans;
    }
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        vector<vector<string>>ans;
        map<int,unordered_map<string,int>>mp;
        set<string>v;
        for(auto &x:orders){
            v.insert(x[2]);
            ++mp[get(x[1])][x[2]];
        }
        vector<string>k;
        k.push_back("Table");
        for(auto &x:v) k.push_back(x);
        ans.push_back(k);
        for(auto &x:mp){
            k.clear();
            k.push_back(to_string(x.first));
            for(int i=1;i<ans[0].size();++i){
                k.push_back(to_string(x.second[ans[0][i]]));
            }
            ans.push_back(k);
        }
        return ans;
    }
};