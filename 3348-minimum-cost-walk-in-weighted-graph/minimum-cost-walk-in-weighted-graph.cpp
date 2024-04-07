class UnionFind{
    vector<int>par,wt;
    public:
        UnionFind(int n){
            wt.resize(n,-1);
            for(int i=0;i<n;++i){
                par.push_back(i);
            }
        }

        int find(int u){
            if(par[u] == u) return u;
            return par[u]=find(par[u]);
        }

        void merge(int u,int v,int w){
            int pu = find(u);
            int pv = find(v);
            if(pu != pv){
                par[pv]=pu;
                wt[pu] &= (wt[pv]);
            }
            wt[pu] &= w;
        }

        int getCost(int u,int v){
            int pu = find(u);
            int pv = find(v);
            if(u == v) return 0;
            else if(pu != pv) return -1;
            else return wt[pu];
        }

};


class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        UnionFind uf(n+1);
        for(auto &x:edges) uf.merge(x[0],x[1],x[2]);
        vector<int>ans;
        for(auto &x:query){
            ans.push_back(uf.getCost(x[0],x[1]));
        }
        return ans;
    }
};