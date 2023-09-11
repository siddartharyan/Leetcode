impl Solution {
    pub fn count_pairs(nums: Vec<i32>, target: i32) -> i32 {
        let len:usize = nums.len();
        let mut ans:i32 = 0;
        for i in 0..len{
            for j in i+1..len{
                if (nums[i]+nums[j]<target){
                    ans+=1;
                }
            }
        }
        return ans;
    }
}