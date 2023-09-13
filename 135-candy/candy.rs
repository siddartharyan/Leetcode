impl Solution {
    pub fn candy(ratings: Vec<i32>) -> i32 {
        let mut ans:Vec<i32>=Vec::new();
        let mut n = ratings.len();
        for i in 0..n{
            ans.push(1);
        }
        for i in 1..n{
            if (ratings[i]>ratings[i-1]){
                ans[i]=ans[i-1]+1;
            }
        }

        for i in (0..n-1).rev() {
            if(ratings[i]>ratings[i+1]) && (ans[i+1] >= ans[i]){
                ans[i]=ans[i+1]+1;
            }
        }

        let mut final_ans: i32 = 0;
        for i in 0..n{
            final_ans += ans[i];
        }
        return final_ans;
    }
}