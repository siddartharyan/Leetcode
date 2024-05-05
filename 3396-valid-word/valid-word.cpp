class Solution {
public:
    bool isVowel(char &c){
        string s = "aeiouAEIOU";
        for(auto &x:s){
            if(x==c) return true;
        }
        return false;
    } 
    bool isValid(string word) {
        int n = word.length();
        if(n>=3){
            int v=0,c=0;
            for(auto &x:word){
                if(x>='a' && x<='z'){
                    if(isVowel(x)) ++v;
                    else ++c;
                }else if(x>='A' && x<='Z'){
                    if(isVowel(x)) ++v;
                    else ++c;
                }else if(x>='0' && x<='9') continue;
                else return false;
            }
            return v>0 && c>0;
        }
        return false;
    }
};