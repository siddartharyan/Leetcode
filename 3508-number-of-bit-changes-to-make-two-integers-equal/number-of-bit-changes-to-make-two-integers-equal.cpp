class Solution {
public:
    int minChanges(int n, int k) {
        int ans = 0;
        int n1 = 0,n2 = 0;
        for(int i=31;i>=0;--i){
            n1 = (n>>i) & 1;
            n2 = (k>>i) & 1;
            if(n1 != n2){
                if(n1 == 1 && n2 == 0) ++ans;
                else return -1;
            }
        }
        return ans;
    }
};