class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(),items.end());
        vector<pair<int,int>>v;
        for(int i=0;i<queries.size();++i) v.push_back({queries[i],i});
        sort(v.begin(),v.end());
        vector<int>ans(queries.size());
        int i=0,j=0,val=0;
        while(j<v.size()){
            while(i<items.size() && items[i][0]<=v[j].first){
                val=max(val,items[i][1]);
                ++i;
            }
            ans[v[j].second]=val;
            ++j;
        }
        return ans;
    }
};