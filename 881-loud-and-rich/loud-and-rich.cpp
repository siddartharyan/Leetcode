class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<int>indegree(n,0);
        unordered_map<int,vector<int>>mp;
        for(auto x:richer) {
            mp[x[0]].push_back(x[1]);
            ++indegree[x[1]];
        }
        queue<int>q;
        vector<int>ans(n);
        for(int i=0;i<n;++i){
            if(indegree[i] == 0) q.push(i);
            ans[i]=i;
        }
        while(!q.empty()){
            int f = q.front();
            q.pop();
            for(auto x:mp[f]){
                if(quiet[ans[x]] > quiet[ans[f]]) ans[x]=ans[f];
                if(--indegree[x] == 0) q.push(x);
            }
        }

        return ans;
    }
};