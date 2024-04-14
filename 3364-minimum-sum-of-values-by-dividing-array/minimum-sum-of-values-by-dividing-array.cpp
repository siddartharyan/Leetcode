class Solution {
public:
    vector<vector<unordered_map<int,int>>>dp;
    int solve(vector<int>&nums,vector<int>&a,int i,int j,int c,int &n,int &m){
        if(i>=n){
            if(j>=m) return 0;
            else return 1e7;
        }
        else if(j>=m) return 1e7;
        if(dp[i][j].count(c)) return dp[i][j][c];
        int sI = 1e7;
        if((c & nums[i]) == a[j]){
            sI = nums[i] + solve(nums,a,i+1,j+1,(1<<20)-1,n,m);
        }
        int sE = solve(nums,a,i+1,j,(c&nums[i]),n,m);
        return dp[i][j][c]=min(sI,sE);
    }
    int minimumValueSum(vector<int>& nums, vector<int>& a) {
        int n = nums.size();
        int m = a.size();
        dp.resize(n,vector<unordered_map<int,int>>(10));
        int ans = solve(nums,a,0,0,(1<<20)-1,n,m);
        return ans == 1e7?-1:ans;
    }
};