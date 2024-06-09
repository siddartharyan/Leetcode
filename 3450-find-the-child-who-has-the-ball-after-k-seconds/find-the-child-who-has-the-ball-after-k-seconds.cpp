class Solution {
public:
    int numberOfChild(int n, int k) {
        int start=0;
        bool f = true;
        while(k--){
            if(f){
                if(start != n-1){
                    ++start;
                }else{
                    start=n-2;
                    f=false;
                }
            }else{
                if(start != 0){
                    --start;
                }else{
                    start=1;
                    f=true;
                }
            }
        }
        return start;
    }
};