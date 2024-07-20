class Solution {
public:
    int minimumLength(string s) {
        vector<int>v(26);
        int ans = 0;
        for(auto &x:s){
            ++v[x-'a'];
        }
        int k = 0;
        for(auto &x:v){
            if(x>=3){
                k = x;
                while(k >= 3){
                    k-=2;
                }
                ans += k;
            }
            else ans += x;
        }
        return ans;
    }
};