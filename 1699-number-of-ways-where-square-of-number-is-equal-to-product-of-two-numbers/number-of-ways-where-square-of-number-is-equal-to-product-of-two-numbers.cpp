class Solution {
public:
    int solve(vector<int>&a1,vector<int>&a2){
        int ans = 0;
        unordered_map<int,int>mp;
        for(auto &x:a2) ++mp[x];
        for(auto &x:a1){
            int i=0,j=a2.size()-1;
            long long k = pow(x,2);
            while(i<j){
                long long l = (long long)a2[i]*a2[j];
                if(l == k){
                    if(a2[i] == a2[j]){
                        ans += (mp[a2[i]]*(mp[a2[i]]-1)/2);
                    }
                    else ans += (mp[a2[i]]*mp[a2[j]]);
                    i+=mp[a2[i]];
                    j-=mp[a2[j]];
                }else if(l>k){
                    j -= mp[a2[j]];
                }else{
                    i += mp[a2[i]];
                }
            }
        }
        return ans;
    }
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        return solve(nums1,nums2)+solve(nums2,nums1);
    }
};