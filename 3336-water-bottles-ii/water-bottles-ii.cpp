class Solution {
public:
    int maxBottlesDrunk(int nB, int nE) {
        int ans = 0;
        int empty=nB;
        while(true){
            ans += nB;
            if(empty >= nE){
                nB = 1;
                empty -= nE;
                ++nE;
            }else{
                break;
            }
            ++empty;
        }
        return ans;
    }
};