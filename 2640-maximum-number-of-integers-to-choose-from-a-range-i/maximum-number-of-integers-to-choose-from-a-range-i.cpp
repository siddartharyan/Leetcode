class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int>s;
        for(auto x:banned) s.insert(x);
        int sum = 0;
        int cnt = 0;
        int i = 1;
        while(i<=n && sum<=maxSum){
            if(s.find(i) == s.end() && sum +i <= maxSum){
                ++cnt;
                sum += i;
            }
            ++i;
        }
        return cnt;
    }
};