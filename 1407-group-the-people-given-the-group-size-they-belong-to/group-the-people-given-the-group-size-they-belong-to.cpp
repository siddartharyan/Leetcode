class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& g) {
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<g.size();++i){
            mp[g[i]].push_back(i);
        }
        vector<vector<int>>ans;
        int size = 0;
        vector<int>k;
        for(auto x:mp){
            size=x.first;
            k.clear();
            for(auto y:x.second){
                if(size == k.size()){
                    ans.push_back(k);
                    k.clear();
                }
                k.push_back(y);
            }
            if(size == k.size()){
                ans.push_back(k);
            }
        }
        return ans;
    }
};