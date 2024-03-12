class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();
        vector<int>z;
        for(int i=0;i<n;++i) if(nums[i] == 0) z.push_back(i);
        int ans = 0;
        int start=0,end=0,first=0,last=0,c=0;
        if(z.size() == n) return 0;
        z.push_back(n);
        long long prod=1;
        for(int i=0;i<z.size();++i){
            start=(i==0)?0:z[i-1]+1;
            end=z[i]-1;
            first=-1,last=-1;
            prod=1;
            c=0;
            for(int i=start;i<=end;++i){
                prod*=nums[i];
                if(nums[i]<0){
                    if(first==-1) first=c;
                    last=c;
                }
                if(prod > INT_MAX) prod=1;
                else if(prod<INT_MIN) prod=-1;
                ++c;
            }
            if(prod>0) ans=max(ans,end-start+1);
            else if(prod<0){
                ans=max(ans,c-(first+1));
                ans=max(ans,c-(c-last));
            }
        }
        return ans;
    }
};