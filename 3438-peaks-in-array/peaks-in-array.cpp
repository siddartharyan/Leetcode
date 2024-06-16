class Solution {
public:
    const static int n = 100005;
    int bit[n]={};
    int query(int i){
        int ans= 0;
        while(i>0){
            ans += bit[i];
            i-=(i&(-i));
        }
        return ans;
    }
    void add(int i,const int &v){
        while(i<n){
            bit[i] += v;
            i += (i&(-i));
        }
    }
    int isPeak(int i,int &n,vector<int>&nums){
        return i+1<n && i-1>=0 && (nums[i]>nums[i-1] && nums[i]>nums[i+1]);
    }
    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        for(int i=0;i<n;++i){
            if(isPeak(i,n,nums)){
                add(i,1);
            }
        }
        vector<int>ans;
        int j=0,val=0;
        for(auto &x:queries){
            if(x[0] == 1){
                val = (x[2]-x[1]<2?0:query(x[2])-(x[1] == 0?0:query(x[1]-1))-isPeak(x[2],n,nums)-isPeak(x[1],n,nums));
                ans.push_back(val);
            }else{
                vector<int>prev;
                j=x[1],val=x[2];
                for(int k=-1;k<2;++k){
                    prev.push_back(isPeak(j+k,n,nums));
                }
                nums[j]=val;
                for(int k=-1;k<2;++k){
                    if(prev[k+1] != isPeak(j+k,n,nums)){
                        add(j+k,prev[k+1]?-1:isPeak(j+k,n,nums));
                    }
                }
            }
        }
        return ans;
    }
};