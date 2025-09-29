impl Solution {
    pub fn min_pair_sum(mut nums: Vec<i32>) -> i32 {
        nums.sort_unstable();

        let mut l: usize = 0;
        let mut r = nums.len() - 1;
        let mut max_sum = 0; //maximum sum of minimized pairs  

        while l < r {
            max_sum = max_sum.max(nums[r] + nums[l]);
            l += 1;
            r -= 1;
        }

        max_sum
    }
}
