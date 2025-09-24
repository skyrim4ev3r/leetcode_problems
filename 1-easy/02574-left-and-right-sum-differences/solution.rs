impl Solution {
    pub fn left_right_difference(nums: Vec<i32>) -> Vec<i32> {

        let mut res = vec![0_i32; nums.len()];

        let mut sum = 0_i32;
        for i in 0..nums.len() {
            res[i] += sum;
            sum += nums[i];
        }

        sum = 0;
        for i in (0..nums.len()).rev() {
            res[i] = (res[i] - sum).abs();
            sum += nums[i];
        }

        res
    }
}
