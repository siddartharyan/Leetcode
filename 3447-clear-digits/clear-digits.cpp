class Solution {
public:
    string clearDigits(string s) {
        vector<int>digit,nrml;
        char c = '0';
        for(int i=0;i<s.size();++i){
            c = s[i];
            if(c>='a' && c<='z'){
                nrml.push_back(i);
            }else{
                if(!digit.size() && nrml.size()>0) nrml.pop_back();
                else digit.push_back(i);
            }
        }
        unordered_set<int>se;
        while(!nrml.empty()){
            se.insert(nrml.back());
            nrml.pop_back();
        }
        while(!digit.empty()){
            se.insert(digit.back());
            digit.pop_back();
        }
        string ans = "";
        for(int i=0;i<s.size();++i){
            if(se.find(i) != se.end()) ans.push_back(s[i]);
        }
        return ans;
    }
};