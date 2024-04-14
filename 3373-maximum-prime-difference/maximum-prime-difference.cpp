class Solution {
public:
    unordered_set<int>s;
    void init(){
        vector<int>v{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
        for(auto &x:v) s.insert(x);
    }
    int maximumPrimeDifference(vector<int>& nums) {
        init();
        int start=-1,end=-1;
        int n = nums.size();
        for(int i=0;i<n;++i){
            if(s.find(nums[i]) != s.end()){
                start=i;
                break;
            }
        }
        for(int i=n-1;i>=0;--i){
            if(s.find(nums[i]) != s.end()){
                end = i;
                break;
            }
        }
        return end-start;
    }
};