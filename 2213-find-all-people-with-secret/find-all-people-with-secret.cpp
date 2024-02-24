class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& m, int f) {
        vector<int>ans;
        unordered_map<int,vector<pair<int,int>>>mp;
        for(auto x:m){
            mp[x[0]].push_back({x[1],x[2]});
            mp[x[1]].push_back({x[0],x[2]});
        }
        vector<int>vis(n,false);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p;
        p.push({0,0});
        p.push({0,f});
        while(!p.empty()){
            auto [time,per] = p.top();
            p.pop();
            vis[per]=true;
            for(auto [p1,t1]:mp[per]){
                if(!vis[p1] && t1>=time) p.push({t1,p1});
            }
        }

        for(int i=0;i<n;++i){
            if(vis[i]) ans.push_back(i);
        }
        return ans;
    }
};