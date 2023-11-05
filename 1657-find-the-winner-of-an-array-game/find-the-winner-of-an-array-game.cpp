class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int max_ele=0;
        for(auto x:arr) max_ele=max(x,max_ele);
        int cnt=0,val=arr[0];
        for(int i=1;i<arr.size();++i){
            if(val>arr[i]){
                ++cnt;
            }else{
                cnt=1;
                val=arr[i];
            }
            if(val == max_ele || cnt == k) return val;
        }
        return -1;
    }
};