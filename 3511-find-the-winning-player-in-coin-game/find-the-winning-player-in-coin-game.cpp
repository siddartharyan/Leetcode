class Solution {
public:
    string losingPlayer(int x, int y) {
        bool f = false;
        while(true){
            if(x==0 || y<4) break;
            --x;
            y-=4;
            f=!f;
        }
        return f?"Alice":"Bob";
    }
};