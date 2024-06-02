class Solution {
public:
    int minimumChairs(string s) {
        int ans = 0,ch=0;
        for(int i=0;i<s.size();++i){
            if(s[i] == 'E'){
                ++ch;
                ans=max(ans,ch);
            }else{
                --ch;
            }
        }
        return ans;
    }
};