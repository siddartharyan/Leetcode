class Solution {
public:
    int minimumLines(vector<vector<int>>& s) {
        int ans = 0;
        int n = s.size();
        sort(s.begin(),s.end());
        long double p = INT_MIN;
        long double c = 0.000;
        long double x1 = 0.0000,y1=0.0000;
        for(int i=1;i<n;++i){
            x1 = 1.0*s[i][1]-1.0*s[i-1][1];
            y1 = 1.0*s[i][0]-1.0*s[i-1][0];
            c = x1/y1;
            if(p != c) ++ans;
            p = c;
        }
        return ans;
    }
};