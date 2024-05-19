class Solution {
public:
    typedef long long ll;
    void solve(vector<vector<int>>&v,vector<int>&nums){
        ll k = 0;
        for(int i=0;i<nums.size();++i){
            k = nums[i];
            for(int j=0;j<10 && k>0;++j){
                ++v[j][k%10];
                k/=10;
            }
        }
    }
    long long sumDigitDifferences(vector<int>& nums) {
        ll ans = 0,n = nums.size();
        vector<vector<int>>v(10,vector<int>(10,0));
        solve(v,nums);
        ll k = 0,re=0;
        for(int i=0;i<n;++i){
            k = nums[i];
            for(int j=0;j<10 && k>0;++j){
                re = k%10;
                ans += (n-v[j][re]);
                // cout<<j<<" "<<re<<" "<<v[j][re]<<endl;
                // // --v[j][re];
                k/=10;
            }
            // cout<<endl;
        }
        return ans/2;
    }
};