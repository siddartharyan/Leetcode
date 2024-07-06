class Solution {
public:
    long long maximumPoints(vector<int>& e, int c) {
        if(c==0) return 0;
        long long ans = 0;
        int n = e.size();
        int ele = INT_MAX;
        long long int sum= 0;
        for(auto &x:e){
            ele=min(ele,x);
        }
        if(ele>c) return 0;
        bool f = true;
        for(auto &x:e){
            if(x != ele) sum += x;
            else if(x == ele){
                if(f){
                    f=false;
                    continue;
                }
                sum += x;
            }
        }
        sum += c;
        ans = sum/ele;
        return ans;
    }
};