class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& p, vector<int>& h, string d) {
        stack<int>s;
        vector<int>v;
        int n = d.size();
        for(int i=0;i<n;++i) v.push_back(i);
        sort(v.begin(),v.end(),[&](int l,int r){
            return p[l]<p[r];
        });
        vector<int>ans;
        int k = 0;
        for(auto &x:v){
            if(d[x] == 'R') s.push(x);
            else{
                while(!s.empty() && h[x]>0){
                    k = s.top();
                    s.pop();
                    if(h[k] > h[x]){
                        h[k]-=1;
                        h[x]=0;
                        s.push(k);
                    }else if(h[k] < h[x]){
                        h[x]-=1;
                        h[k]=0;
                    }else{
                        h[x]=0;
                        h[k]=0;
                    }
                }
            }
        }
        for(int i=0;i<n;++i){
            if(h[i]>0) ans.push_back(h[i]);
        }
        return ans;
    }
};