class Solution {
public:
    unordered_map<string,priority_queue<string,vector<string>,greater<string>>>mp;
    vector<string>ans;
    void solve(string s){
        while(!mp[s].empty()){
            string k = mp[s].top();
            mp[s].pop();
            solve(k);
        }
        ans.push_back(s);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto x:tickets){
            mp[x[0]].push(x[1]);
        }
        solve("JFK");
        reverse(ans.begin(),ans.end());
        return ans;
    }
};