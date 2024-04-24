class Solution {
public:
    string largestMerge(string w1, string w2) {
        int n = w1.size();
        int m = w2.size();
        string ans = "";
        string s1="",s2="";
        int i=0,j=0;
        while(true){
            if(i==n && j==m) break;
            if(i<n && j<m){
                s1=w1.substr(i);
                s2=w2.substr(j);
                if(s1>s2){
                    ans.push_back(w1[i++]);
                }else{
                    ans.push_back(w2[j++]);
                }
            }else{
                while(i<n) ans.push_back(w1[i++]);
                while(j<m) ans.push_back(w2[j++]);
            }
        }
        return ans;
    }
};