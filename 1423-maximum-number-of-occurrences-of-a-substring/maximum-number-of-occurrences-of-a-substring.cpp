class Solution {
public:
    int maxFreq(string s, int mL, int ms, int mS) {
        unordered_map<string,int>mp;
        int n = s.size();
        int ans= 0;
        for(int i=0;i<n;++i){
            string s1 = s.substr(i,ms);
            vector<int>v(26);
            int u = 0;
            for(auto &x:s1){
                if(v[x-'a'] == 0){
                    ++u;
                    ++v[x-'a'];
                }
            }
            if(u<=mL &&(s1.size() >= ms && s1.size() <= mS)){
                ++mp[s1];
                ans=max(ans,mp[s1]);
            }
            for(int j=ms+i;j <n && j<=i+mS;++j){
                if(v[s[j]-'a'] == 0){
                    ++v[s[j]-'a'];
                    ++u;
                }
                s1 += s[j];
                if(u<=mL &&(s1.size() >= ms && s1.size()<=mS)) ++mp[s1];
                ans = max(ans,mp[s1]);
                if(u>mL) break;
            }
            ans=max(ans,mp[s1]);
        }
        return ans;
    }
};