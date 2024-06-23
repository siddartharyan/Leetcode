class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int ans = 0;
        int n = nums.size();
        priority_queue<pair<int,int>>ma;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>mi;
        int s = 0;
        for(int e=0;e<n;++e){
            ma.push({nums[e],e});
            mi.push({nums[e],e});
            while((ma.top().first-mi.top().first)>limit){
                s=min(ma.top().second,mi.top().second)+1;
                while(ma.top().second<s) ma.pop();
                while(mi.top().second<s) mi.pop();
            }
            ans = max(ans,e-s+1);
        }
        return ans;
    }
};