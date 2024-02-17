class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        unordered_set<int>s;
        for(auto x:nums) s.insert(x);
        for(int i=0;i<32;++i){
            int x = (1<<i);
            if(s.find(x) == s.end()) return x;
        }
        return -1;
    }
};