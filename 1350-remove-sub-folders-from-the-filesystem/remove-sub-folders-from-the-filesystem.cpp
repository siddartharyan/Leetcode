class Solution {
public:
    unordered_set<string>s;
    bool canContain(string &b){
        string s1 = "";
        for(auto &x:b){
            if(x == '/' && s1 != ""){
                if(s.find(s1) != s.end()){
                    s.insert(b);
                    return true;
                }
            }
            s1 += x;
        }
        s.insert(b);
        return false;
    }
    vector<string> removeSubfolders(vector<string>& folder) {
        int n=folder.size();
        vector<string>ans;
        sort(folder.begin(),folder.end());
        for(auto &x:folder){
            if(!canContain(x)){
                ans.push_back(x);
            }
        }
        return ans;
    }
};