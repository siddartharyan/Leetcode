class Solution {
    unordered_map<int,vector<int>>mp;
private:
    bool dfs(int node,int flag,vector<int>&vis,vector<int>&val){
        vis[node]=1;
        val[node]=flag;
        for(auto x:mp[node]){
            if(!vis[x]){
                if(!dfs(x,!flag,vis,val)) return false;
            }else if(vis[x] && val[x] == val[node]){
                return false;
            }
        }
        return true;
    }
public:
    bool possibleBipartition(int n, vector<vector<int>>& d) {
        for(auto x:d){
            mp[x[0]].push_back(x[1]);
            mp[x[1]].push_back(x[0]);
        }
        vector<int>vis(n+1,0),val(n+1,-1);
        for(int i=1;i<n+1;++i){
            if(!vis[i]){
                if(!dfs(i,0,vis,val)) return false;
            }
        }
        return true;
    }
};