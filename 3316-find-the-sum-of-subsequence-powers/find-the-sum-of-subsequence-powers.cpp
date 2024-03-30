class Solution {
public:
    int M = 1e9+7;
    int dp[51][51][51][51];
    int solve(int i,int n,int k,int y,int z,vector<int>&nums){
        if(k==0){
            return nums[z]-nums[y];
        }
        if(i>=n) return 0;
        if(dp[i][k][y][z] != -1) return dp[i][k][y][z];
        long long ans = 0;
        int p = -1,c=0,k1=0;
        for(int j=i;j<n;++j){
            p = i-1;
            if(p==-1) ans = (ans+solve(j+1,n,k-1,y,z,nums))%M;
            else{
                k1 = nums[z]-nums[y];
                c = nums[j]-nums[p];
                if(c<k1) ans =(ans + solve(j+1,n,k-1,p,j,nums))%M;
                else ans = (ans+solve(j+1,n,k-1,y,z,nums))%M;
            }
        }
        return dp[i][k][y][z]=ans%M;
    }
    int sumOfPowers(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        memset(dp,-1,sizeof(dp));
        return solve(0,n,k,0,n-1,nums);
    }
};