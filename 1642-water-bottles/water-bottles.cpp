class Solution {
public:
    int numWaterBottles(int a, int b) {
        if(a==0 or b>a) return a;
        return (a*b-1)/(b-1);
    }
};