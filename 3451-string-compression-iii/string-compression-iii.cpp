class Solution {
public:
    string compressedString(string word) {
        string ans = "";
        char c = '0',p = word[0];
        int cnt = 1;
        int n = word.size();
        for(int i=1;i<n;++i){
            c = word[i];
            if(p == c){
                ++cnt;
                if(cnt == 9){
                    ans.push_back('9');
                    ans.push_back(c);
                    cnt = 0;
                }
            }else{
                if(cnt != 0){
                    ans.push_back((char)('0'+cnt));
                    ans.push_back(p);
                }
                cnt=1;
            }
            p=c;
        }
        if(cnt != 0){
            ans.push_back((char)('0'+cnt));
            ans.push_back(p);
        }
        return ans;
    }
};