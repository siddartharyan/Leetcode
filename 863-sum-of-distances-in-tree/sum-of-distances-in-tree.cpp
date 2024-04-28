class Solution {
public:
    unordered_map<int,vector<int>>mp;
    int N;
    vector<int>ans,cnt;
    void solve(int node,int p){
        for(auto &x:mp[node]){
            if(x != p){
                solve(x,node);
                cnt[node]+=cnt[x];
                ans[node] += ans[x]+cnt[x];
            }
        }
    }
    void solve2(int node,int p){
        for(auto &x:mp[node]){
            if(x != p){
                ans[x]=ans[node]-cnt[x]+(N-cnt[x]);
                solve2(x,node);
            }
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        N = n;
        for(auto &x:edges){
            mp[x[0]].push_back(x[1]);
            mp[x[1]].push_back(x[0]);
        }
        ans.resize(n,0);
        cnt.resize(n,1);
        solve(0,-1);
        solve2(0,-1);
        return ans;
    }
};