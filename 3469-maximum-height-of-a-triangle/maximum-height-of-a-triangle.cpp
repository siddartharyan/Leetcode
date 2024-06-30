class Solution {
public:
    int solve(int a,int b){
        int cnt = 0;
        bool f = false;
        int t = 1;
        while(true){
            if(!f){
                if(t>a) break;
                a -= t;
            }else{
                if(t>b) break;
                b -= t;
            }
            f = !f;
            ++t;
        }
        return t-1;
    }
    int maxHeightOfTriangle(int red, int blue) {
        return max(solve(red,blue),solve(blue,red));
    }
};