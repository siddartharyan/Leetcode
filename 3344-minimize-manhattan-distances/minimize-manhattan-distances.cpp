class Solution {
public:
    array<int,3> solve(vector<vector<int>>&p,int k=-1){
        int s[2]={INT_MAX,INT_MIN};
        int d[2]={INT_MAX,INT_MIN};
        int s_i[2]={-1,-1},d_i[2]={-1,-1};
        for(int i=0;i<p.size();++i){
            if(i==k) continue;
            if(s[0]>p[i][0]+p[i][1]){
                s[0]=p[i][0]+p[i][1];
                s_i[0]=i;
            }
            if(s[1]<p[i][0]+p[i][1]){
                s[1]=p[i][0]+p[i][1];
                s_i[1]=i;
            }
            if(d[0]>p[i][0]-p[i][1]){
                d[0]=p[i][0]-p[i][1];
                d_i[0]=i;
            }
            if(d[1]<p[i][0]-p[i][1]){
                d[1]=p[i][0]-p[i][1];
                d_i[1]=i;
            }
        }
        if(s[1]-s[0] > d[1]-d[0]){
            return {s[1]-s[0],s_i[0],s_i[1]};
        }
        return {d[1]-d[0],d_i[0],d_i[1]};
    }
    int minimumDistance(vector<vector<int>>& points) {
        auto [_,i,j] = solve(points);
        return min(solve(points,i)[0],solve(points,j)[0]);
    }
};