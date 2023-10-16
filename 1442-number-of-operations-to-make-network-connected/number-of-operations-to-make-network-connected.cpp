class DisjointSet{
    vector<int>parent,size;
    public:
        DisjointSet(int n){
            size.resize(n,0);
            for(int i=0;i<n;++i){
                parent.push_back(i);
            }
        }
        int findPar(int x){
            if(x == parent[x]) return x;
            return parent[x] = findPar(parent[x]);
        }
        void unionBySize(int u,int v){
            int pu = findPar(u);
            int pv = findPar(v);
            if(pu==pv) return ;
            int ru = size[pu];
            int rv = size[pv];
            if(ru < rv){
                parent[pu] = pv;
                size[pv] += size[pu];
            }else{
                parent[pv] = pu;
                size[pu] += size[pv];
            }
        }

        int getComponents(){
            int ans = 0;
            for(int i=0;i<parent.size();++i){
                if(parent[i] == i) ++ans;
            }
            return ans;
        }
};


class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int canbeIgnored = 0;
        for(auto x:connections){
            if(ds.findPar(x[0]) == ds.findPar(x[1])){
                ++canbeIgnored;
            }else{
                ds.unionBySize(x[0],x[1]);
            }
        }
        int comp = ds.getComponents();
        if(comp == 1) return 0;
        bool canBe = canbeIgnored >= (comp-1);
        return canBe?comp-1:-1;
    }
};