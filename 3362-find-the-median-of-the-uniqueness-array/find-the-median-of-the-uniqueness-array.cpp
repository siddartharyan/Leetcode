class Solution {
public:
    long long solve(vector<int>&nums,int &m,int &n){
        unordered_map<long long,int>mp;
        long long ans = 0;
        for(int i=0,j=0;i<n;++i){
            ++mp[nums[i]];
            while(mp.size()>m){
                --mp[nums[j]];
                if(mp[nums[j]] == 0) mp.erase(nums[j]);
                ++j;
            }
            ans += (i-j+1);
        }
        return ans;
    }
    int medianOfUniquenessArray(vector<int>& nums) {
        int n = nums.size();
        int l = 0,r=unordered_set<int>(nums.begin(),nums.end()).size();
        long t = ((long)(n)*((long)n+1))/2;
        int ans= INT_MAX;
        while(l<=r){
            int m = l+(r-l)/2;
            if(2*(solve(nums,m,n)) >= t){
                ans=min(ans,m);
                r=m-1;
            }else{
                l=m+1;
            }
        }
        return ans;
    }
};