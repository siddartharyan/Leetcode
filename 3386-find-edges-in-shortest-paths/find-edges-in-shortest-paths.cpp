typedef long long ll;
class Solution {
public:
    unordered_map<int,vector<pair<int,int>>>mp;
    vector<ll> solve(const int &s,int &m,int &n){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p;
        vector<ll>d(n,INT_MAX);
        vector<bool>v(n);
        p.push({0,s});
        pair<int,int>t;
        while(!p.empty()){
            t=p.top();
            p.pop();
            if(v[t.second]) continue;
            v[t.second]=true;
            d[t.second]=t.first;
            for(auto &x:mp[t.second]){
                if(!v[x.first]){
                    p.push({t.first+x.second,x.first});
                }
            }
        }
        return d;
    }
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        for(auto &x:edges){
            mp[x[0]].push_back({x[1],x[2]});
            mp[x[1]].push_back({x[0],x[2]});
        }
        vector<ll>d1 = solve(0,m,n);
        vector<ll>d2 = solve(n-1,m,n);
        vector<bool>ans(m);
        ll k = d1[n-1];
        int u,v,w;
        for(int i=0;i<m;++i){
            u=edges[i][0],v=edges[i][1],w=edges[i][2];
            if(d1[u]+(ll)w+d2[v] == k){
                ans[i]=true;
            }
            if(d2[u]+(ll)w+d1[v] == k){
                ans[i]=true;
            }
        }
        return ans;
    }
};