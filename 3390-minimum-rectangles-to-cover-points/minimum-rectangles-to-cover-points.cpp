class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        int n = points.size();
        sort(points.begin(),points.end());
        int f = points[0][0], ans = 1;
        for(int i=1;i<n;++i){
            if(f+w < points[i][0]){
                ++ans;
                f = points[i][0];
            }
        }
        return ans;
    }
};