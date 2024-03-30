class Solution {
public:
    int getNum(vector<int>&v){
        int ans = 0;
        for(int i=31;i>=0;--i){
            if(v[i] > 0){
                ans += (1<<i);
            }
        }
        return ans;
    }
    void dec(vector<int>&v,int n){
        for(int i=31;i>=0;--i){
            if(n & (1<<i)){
                --v[i];
            }
        }
    }
    void inc(vector<int>&v,int n){
        for(int i=31;i>=0;--i){
            if(n & (1<<i)){
                ++v[i];
            }
        }
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int ans = INT_MAX;
        int n = nums.size();
        vector<int>v(32);
        int s = 0,j=0;
        for(int i=0;i<n;++i){
            inc(v,nums[i]);
            s=getNum(v);
            while(s >= k && j<=i){
                ans=min(ans,i-j+1);
                dec(v,nums[j]);
                s=getNum(v);
                ++j;
            }
        }
        return ans == INT_MAX?-1:ans;
    }
};