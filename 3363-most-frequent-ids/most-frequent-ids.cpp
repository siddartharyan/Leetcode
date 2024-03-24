class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        vector<long long>ans;
        priority_queue<pair<long long,long long>>p;
        unordered_map<int,long long>mp;
        int n = nums.size();
        for(int i=0;i<n;++i){
            mp[nums[i]] += freq[i];
            while(!p.empty() && p.top().first != mp[p.top().second]) p.pop();
            if(mp[nums[i]] > 0) p.push({mp[nums[i]],nums[i]});
            if(p.empty()) ans.push_back(0);
            else ans.push_back(p.top().first);
        }
        return ans;
    }
};