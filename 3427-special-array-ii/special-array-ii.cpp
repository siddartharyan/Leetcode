class Solution {
public:
    bool isGood(int &a,int &b){
        return (a%2==0 && b%2 == 1) || (a%2==1 && b%2==0);
    }
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(),m = queries.size();
        vector<bool>ans;
        unordered_map<int,int>mp;
        int last = -1;
        for(int i=0;i<n-1;++i){
            if(isGood(nums[i],nums[i+1])){
                mp[i]=last;
                mp[i+1]=last;
            }else{
                mp[i]=last;
                mp[i+1]=i;
                last=i;
            }
        }
        for(auto &x:queries){
            if(mp[x[0]] == mp[x[1]]){
                ans.push_back(true);
            }else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};