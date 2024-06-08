class Solution {
public:
    int findWinningPlayer(vector<int>& s, int k) {
        int n = s.size();
        deque<int>q;
        int m = INT_MIN;
        int index = -1;
        for(int i=0;i<n;++i){
            q.push_back(i);
            if(s[i] > m){
                m = s[i];
                index = i;
            }
        }
        if(k>=n) return index;
        int cnt = 0,k1=0,k2=0;
        int f=-1,b=-1;
        m = -1;
        while(true){
            k1 = q.front();
            q.pop_front();
            k2 = q.front();
            q.pop_front();
            if(m==-1){
                if(s[k1] > s[k2]){
                    m=k1;
                    ++cnt;
                    f=k1;
                    b=k2;
                }else{
                    m=k2;
                    f=k2;
                    b=k1;
                    ++cnt;
                }
            }else{
                if(s[k1]>s[k2]){
                    if(m==k1){
                        ++cnt;
                    }
                    else{
                        m=k1;
                        cnt=1;
                    }
                    f=k1,b=k2;
                }else{
                    if(m==k2) ++cnt;
                    else{
                        m=k2;
                        cnt=1;
                    }
                    f=k2,b=k1;
                }
            }
            q.push_front(f);
            q.push_back(b);
            if(cnt >= k) return m;
        }
        return -1;
    }
};