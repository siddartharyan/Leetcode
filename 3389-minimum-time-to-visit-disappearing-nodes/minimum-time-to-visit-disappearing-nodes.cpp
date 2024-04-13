class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& di) {
        unordered_map<int,vector<pair<int,int>>>mp;
        for(auto &x:edges){
            if(x[0] == x[1]) continue;
            mp[x[0]].push_back({x[1],x[2]});
            mp[x[1]].push_back({x[0],x[2]});
        }
        vector<int>ans(n,-1);
        ans[0]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p;
        p.push({0,0});
        vector<int>v(n,INT_MAX),dist(n,INT_MAX);
        dist[0]=0;
        pair<int,int>t;
        while(!p.empty()){
            t = p.top();
            p.pop();
            if(v[t.second] == 1) continue;
            if(t.first >= di[t.second]) continue;
            v[t.second]=1;
            for(auto &x:mp[t.second]){
                if(t.first+x.second < dist[x.first] and t.first+x.second <= di[x.first]){
                    dist[x.first]=t.first+x.second;
                    p.push({t.first+x.second,x.first});
                }
            }
        }
        for(int i=1;i<n;++i){
            if(dist[i] < di[i]) ans[i]=dist[i];
        }
        return ans;
    }
};