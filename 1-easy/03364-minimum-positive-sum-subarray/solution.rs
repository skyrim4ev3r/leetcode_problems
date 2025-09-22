impl Solution {
    pub fn minimum_sum_subarray(nums: Vec<i32>, l: i32, r: i32) -> i32 {
        let mut min_positive_sum = -1;
        let l = l as usize - 1;
        let r = r as usize - 1;
        let n = nums.len();

        for i in 0..(n - l) {
            let mut sum = 0;
            for j in i..=(i + r).min(n - 1) {
                sum += nums[j];
                if j >= i + l && sum > 0 && (sum < min_positive_sum || min_positive_sum == -1) {
                    min_positive_sum = sum;
                }
            }
        }

        min_positive_sum
    }
}
