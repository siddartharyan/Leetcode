class Solution {
public:
    int solve(vector<int>&v,int &val){
        int n = v.size();
        int l = 0,r = n-1;
        int mid = 0;
        int ans = -1;
        while(l<=r){
            mid = l+(r-l)/2;
            if(v[mid] < val){
                l=mid+1;
                ans=mid;
            }else{
                r=mid-1;
            }
        }
        return ans + 1;
    }
    int minChanges(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mp;
        vector<int>v;
        int f=0,s=0;
        for(int i=0;i<n/2;++i){
            f=max(nums[i],abs(k-nums[i]));
            s=max(nums[n-i-1],abs(k-nums[n-i-1]));
            ++mp[abs(nums[i]-nums[n-i-1])];
            v.push_back(max(f,s));
        }
        sort(v.begin(),v.end());
        int ans = INT_MAX,k1=0;
        for(auto &x:mp){
            f=x.first;
            s=x.second;
            k1=solve(v,f);
            ans=min(ans,n/2-s+k1);
        }
        return ans;
    }
};