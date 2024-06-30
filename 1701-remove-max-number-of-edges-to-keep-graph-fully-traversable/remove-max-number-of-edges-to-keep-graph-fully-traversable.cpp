class UF{
    vector<int>v,s;
    int c;
    public:
        UF(int n){
            for(int i=0;i<=n;++i){
                v.push_back(i);
                s.push_back(1);
            }
            c=n;
        }
    int findPar(int a){
        if(v[a] == a) return a;
        return v[a]=findPar(v[a]);
    }
    int merge(int a,int b){
        int pa = findPar(a);
        int pb = findPar(b);
        if(pa == pb) return 0;
        int sa = s[pa];
        int sb = s[pb];
        if(sa>sb){
            ++s[sa];
            v[pb]=pa;
        }else{
            ++s[sb];
            v[pa]=pb;
        }
        --c;
        return 1;
    }

    bool isOk(){
        return this->c == 1;
    }
};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        UF a(n),b(n);
        int ans = 0;
        int c = edges.size();
        for(auto &x:edges){
            if(x[0] == 3){
                ans += (a.merge(x[1],x[2]) | b.merge(x[1],x[2]));
            }
        }
        for(auto &x:edges){
            if(x[0] == 1) ans += a.merge(x[1],x[2]);
            if(x[0] == 2) ans += b.merge(x[1],x[2]);
        }
        if(a.isOk() && b.isOk()) return c-ans;
        return -1;
    }
};