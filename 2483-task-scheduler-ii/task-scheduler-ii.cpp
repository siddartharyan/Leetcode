class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<int,long long>mp;
        long long day = 0;
        int n = tasks.size();
        for(int i=0;i<n;++i){
            if(mp.find(tasks[i]) == mp.end()){
                ++day;
            }else{
                long long k = mp[tasks[i]];
                if(i-k>space) ++day;
                else{
                    long long t = k+(long long)space+1;
                    if(day >= t) ++day;
                    else day = t;
                }
            }
            mp[tasks[i]]=day;
        }
        return day;
    }
};