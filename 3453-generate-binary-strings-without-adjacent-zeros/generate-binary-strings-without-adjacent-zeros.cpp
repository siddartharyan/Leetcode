class Solution {
public:
    int cal(const string &s){
        int ans = 0;
        int k = 0;
        for(int i=s.size()-1;i>=0;--i){
            ans += (s[i]-'0') * (1<<k);
            ++k;
        }
        return ans;
    }
    bool validate(const string &s){
        for(int i=0;i<s.size()-1;++i){
            if(!(s[i] == '1' || s[i+1] == '1')) return false;
        }
        return true;
    }
    vector<string> validStrings(int n) {
        vector<string>ans;
        queue<string>q;
        q.push("0");
        q.push("1");
        int finalAns = (1<<n);
        while(!q.empty()){
            string s = q.front();
            q.pop();
            if(s.length() == n){
                if(cal(s) < finalAns && validate(s)) ans.push_back(s);
                continue;
            }
            q.push(s+'0');
            q.push(s+'1');
        }
        return ans;
    }
};