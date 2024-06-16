class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        long long ans = 0;
        unordered_map<int,int>mp;
        int n = hours.size();
        for(int i=n-1;i>=0;--i){
            ans += mp[(24-hours[i]%24)%24];
            ++mp[hours[i]%24];
        }
        return ans;
    }
};