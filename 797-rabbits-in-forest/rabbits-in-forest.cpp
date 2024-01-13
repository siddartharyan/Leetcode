class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int>mp;
        int ans = 0;
        for(auto x:answers){
            if(mp[x] == 0){
                ans += (x+1);
                mp[x]=x;
            }else{
                --mp[x];
            }
        }
        return ans;
    }
};