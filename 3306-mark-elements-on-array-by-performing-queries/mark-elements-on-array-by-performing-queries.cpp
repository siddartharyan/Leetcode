class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        long long sum = 0;
        for(auto &x:nums) sum += x;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p;
        int n = nums.size();
        for(int i=0;i<n;++i) p.push({nums[i],i});
        unordered_set<int>s;
        vector<long long>ans;
        int i=-1,k=-1;
        pair<int,int>j;
        for(auto &x:queries){
            i = x[0];
            k = x[1];
            if(s.find(i) == s.end()){
                s.insert(i);
                sum -= nums[i];
            }
            while(k>0 && !p.empty()){
                j=p.top();
                if(s.find(j.second) == s.end()) {
                    --k;
                    sum -= nums[j.second];
                    s.insert(j.second);
                }
                p.pop();
            }
            ans.push_back(sum);
        }
        return ans;
    }
};