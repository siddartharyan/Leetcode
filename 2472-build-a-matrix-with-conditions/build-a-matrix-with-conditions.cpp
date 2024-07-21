class Solution {
public:
    vector<int> topo(vector<vector<int>>&g,const int &n){
        vector<int>ans;
        vector<int>in(n);
        for(int i=1;i<n;++i){
            for(auto &x:g[i]) ++in[x];
        }
        queue<int>q;
        for(int i=1;i<n;++i){
            if(in[i] == 0) q.push(i);
        }
        int k = 0;
        while(!q.empty()){
            k = q.front();
            q.pop();
            ans.push_back(k);
            for(auto &y:g[k]){
                --in[y];
                if(in[y] == 0) q.push(y);
            }
        }
        for(int i=0;i<n;++i) if(in[i] != 0) return {};
        return ans;
    }
    vector<vector<int>> build(const int &n,vector<vector<int>>&g){
        vector<vector<int>>ans;
        for(int i=0;i<n;++i) ans.push_back({});
        for(auto &x:g){
            ans[x[0]].push_back(x[1]);
        }
        return ans;
    }
    void change(vector<int>&r,int &k){
        unordered_set<int>s;
        for(auto &x:r) s.insert(x);
        for(int i=1;i<=k;++i){
            if(s.find(i) == s.end()) r.push_back(i);
        }
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>&r, vector<vector<int>>&c) {
        vector<vector<int>>rg = build(k+1,r);
        vector<vector<int>>cg = build(k+1,c);
        vector<int>rt = topo(rg,k+1);
        vector<int>ct = topo(cg,k+1);
        vector<vector<int>>ans;
        if(rt.size() == 0 || ct.size() == 0 || rt.size() != ct.size()) return ans;
        change(rt,k);
        change(ct,k);
        unordered_map<int,int>mp;
        ans.resize(k,vector<int>(k));
        for(int i=0;i<ct.size();++i){
            mp[ct[i]]=i;
        }
        for(int i=0;i<rt.size();++i){
            ans[i][mp[rt[i]]] = rt[i];
        }
        return ans;
    }
};