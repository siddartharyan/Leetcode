class Solution {
public:
    string findLatestTime(string s) {
        string hr = s.substr(0,2);
        string min = s.substr(3,2);
        if(hr[0] == '?' && hr[1]=='?'){
            hr = "11";
        }else if(hr[0] == '?' && hr[1] != '?'){
            if(hr[1] >='0' && hr[1]<='1'){
                hr[0]='1';
            }else{
                hr[0]='0';
            }
        }else if(hr[0] != '?' && hr[1] == '?'){
            if(hr[0] == '1'){
                hr[1]='1';
            }else{
                hr[1]='9';
            }
        }
        if(min[0] == '?' && min[1] == '?'){
            min="59";
        }else if(min[0] == '?' and min[1] != '?'){
            min[0]='5';
        }else if(min[0] != '?' and min[1] == '?'){
            min[1]='9';
        }
        return hr+':'+min;
    }
};