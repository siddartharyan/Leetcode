class Solution {
public:
    bool checkValidString(string s) {
        int l1 = 0,l2 = 0;
        for(auto &x:s){
            if(x=='(') {
                ++l1,++l2;
            }else if(x==')'){
                --l1,--l2;
            }else{
                --l1,++l2;
            }
            if(l1<0) l1=0;
            if(l2<0) return false;
        }
        return l1==0;
    }
};