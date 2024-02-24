class Solution {
public:
    int racecar(int target) {
        queue<vector<int>>q;
        q.push({0,1,0});
        while(!q.empty()){
            vector<int>t=q.front();
            q.pop();
            if(t[0] == target) return t[2];
            if(t[0]+t[1]<=10000 && t[0]+t[1] > 0){
                q.push({t[0]+t[1],2*t[1],t[2]+1});
            }
            if(t[1]>0 && (t[0]+t[1]>target)){
                q.push({t[0],-1,t[2]+1});
            }
            if(t[1]<0 && (t[0]+t[1]<target)){
                q.push({t[0],1,t[2]+1});
            }
        }
        return -1;
    }
};