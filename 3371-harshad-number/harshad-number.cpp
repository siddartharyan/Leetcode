class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int s = 0;
        int d = x;
        while(d>0){
            s += (d%10);
            d/=10;
        }
        return x%s == 0 ? s : -1;
    }
};