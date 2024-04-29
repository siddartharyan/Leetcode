class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int>s;
        unordered_map<string,int>d;
        for(auto &x:words){
            if(x[0] == x[1]){
                ++s[x];
            }else{
                ++d[x];
            }
        }
        int ans = 0;
        string s1 = "";
        for(auto &x:d){
            s1=x.first;
            swap(s1[0],s1[1]);
            ans += 2*min(d[s1],x.second);
        }
        bool f = false;
        for(auto &x:s){
            if(x.second == 1) f= true;
            else{
                if(x.second%2==1){
                    ans += 2*(x.second-1);
                    f=true;
                }else{
                    ans += 2*x.second;
                }
            }
        }
        return ans+(f?2:0);
    }
};