class Solution {
public:
    int minimumBuckets(string h) {
        int ans = 0;
        int n = h.size();
        for(int i=0;i<n;++i){
            if(h[i] == 'H'){
                if(i-1>=0 && h[i-1] == 'A') continue;
                if(i+1<n && h[i+1] == '.'){
                    h[i+1]='A';
                    ++ans;
                }else if(i-1>=0 && h[i-1] == '.'){
                    h[i-1]='A';
                    ++ans;
                }else if((i+1<n && h[i+1] == 'H') || (i+1 == n)) return -1;
            }
        }
        return ans;
    }
};