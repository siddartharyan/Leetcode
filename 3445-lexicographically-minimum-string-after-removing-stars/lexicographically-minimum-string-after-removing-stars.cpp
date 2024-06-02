class Cmp{
 public:
    bool operator()(const pair<char,int>&a,const pair<char,int>&b) const {
        if(a.first == b.first){
            return a.second < b.second;
        }
        return a.first > b.first;
    }
};

class Solution {
public:
    string clearStars(string s) {
        int n = s.size();
        string ans = "";
        priority_queue<pair<char,int>,vector<pair<char,int>>,Cmp>p;
        for(int i=0;i<n;++i){
            if(s[i] == '*'){
                p.pop();
            }else{
                p.push({s[i],i});
            }
        }
        unordered_set<int>se;
        while(!p.empty()){
            se.insert(p.top().second);
            p.pop();
        }
        for(int i=0;i<n;++i){
            if(se.find(i) != se.end()) ans.push_back(s[i]);
        }
        return ans;
    }
};