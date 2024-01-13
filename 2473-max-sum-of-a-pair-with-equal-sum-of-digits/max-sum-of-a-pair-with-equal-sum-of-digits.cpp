class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int,vector<int>>mp;
        int n = nums.size();
        int sum = 0,k = 0;
        for(auto x:nums){
            sum = 0;
            k = x;
            while(k>0){
                sum += (k%10);
                k/=10;
            }
            mp[sum].push_back(x);
        }
        int ans = -1;
        int first=0,second=0;
        for(auto x:mp){
            vector<int>t=x.second;
            first=-1,second=-1;
            for(auto x:t){
                if(x>first){
                    second=first;
                    first=x;
                }else if(first >= x && x > second){
                    second = x;
                }
            }
            if(first != -1 && second != -1) ans = max(ans,first+second);
        }
        return ans;
    }
};