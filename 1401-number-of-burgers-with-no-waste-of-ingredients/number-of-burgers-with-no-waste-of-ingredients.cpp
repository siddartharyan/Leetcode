class Solution {
public:
    vector<int> numOfBurgers(int t, int c) {
        if(t%2!=0) return {};
        if(t==0 and c==0) return {0,0};
        vector<int>ans;
        //4x+2y=t
        //x+y=c
        //4x+2y=t
        //2x+2y=2*c
        //2x = t-2*c
        //x=(t-2*c)/2
        //y=c-x
        int ans1 = (t-2*c)/2;
        int ans2 = (c-ans1);
        if(ans1<0 || ans2<0) return {};
        return {ans1,ans2};
    }
};