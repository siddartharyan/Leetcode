class Solution {
public:
    vector<long long>dp;
    long long solve(vector<vector<int>>& questions,int i,int n){
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        long long  pick = questions[i][0] + solve(questions,i+questions[i][1]+1,n);
        long long dontPick = solve(questions,i+1,n);
        return dp[i]=max(pick,dontPick);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        dp.resize(n+1,-1);
        return solve(questions,0,n);
    }
};