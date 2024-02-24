class UnionFind{
    private:
        vector<int>p;
        vector<int>r;
    public:
        UnionFind(int n){
            for(int i=0;i<n;++i) p.push_back(i);
            r.resize(n,0);
        }

        int findPar(int x){
            if(p[x] == x) return x;
            return p[x]=findPar(p[x]);
        }

        void merge(int x,int y){
            int px = findPar(x);
            int py = findPar(y);
            if(px != py){
                if(r[px] > r[py]){
                    p[py]=px;
                }else if(r[px] < r[py]){
                    p[px]=py;
                }else{
                    p[py]=px;
                    ++r[px];
                }
            }
        }
        
        bool isConnected(int x,int y){
            return findPar(x) == findPar(y);
        }

        void reset(int x){
            p[x]=x;
            r[x]=0;
        }
};

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int f) {
        auto cmp = [](vector<int>&a,vector<int>&b){
            return a[2]<b[2];
        };
        sort(meetings.begin(),meetings.end(),cmp);
        map<int,vector<pair<int,int>>>mp;
        for(auto x:meetings){
            mp[x[2]].emplace_back(x[0],x[1]);
        }
        UnionFind uf(n);
        uf.merge(f,0);
        vector<int>ans;
        for(auto x:mp){
            for(auto y:x.second){
                uf.merge(y.first,y.second);
            }
            for(auto y:x.second){
                if(!uf.isConnected(y.first,0)){
                    uf.reset(y.first);
                    uf.reset(y.second);
                }
            }
        }

        for(int i=0;i<n;++i){
            if(uf.isConnected(i,0)) ans.push_back(i);
        }
        return ans;
    }
};