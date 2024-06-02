class Solution {
public:
    int merge(vector<vector<int>>&v){
        int n = v.size();
        int start = 0;
        for(int i=1;i<n;++i){
            if(v[start][1] >= v[i][0]){
                v[start][1]=max(v[start][1],v[i][1]);
            }else{
                ++start;
                v[start]=v[i];
            }
        }
        return start;
    }
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        int end = merge(meetings);
        int ans = 0;
        for(int i=0;i<=end;++i){
            ans += ((meetings[i][1]-meetings[i][0])+1);
        }
        return days-ans;
    }
};