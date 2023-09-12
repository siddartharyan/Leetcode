class Solution {
public:
    int minDeletions(string s) {
        vector<int>v(26,0);
        for(auto x:s) ++v[x-'a'];
        int arr[100001]={0};
        for(auto x:v){
            ++arr[x];
        }
        int ans = 0,count=0;
        for(int i=0;i<26;++i){
            count=v[i];
            if(count == 0) continue;
            if(arr[count] > 1){
                while(count>0 && arr[count] != 0){
                    --count;
                    ++ans;
                }
                arr[count]++;
                arr[v[i]]--;
            }
        }
        return ans;
    }
};