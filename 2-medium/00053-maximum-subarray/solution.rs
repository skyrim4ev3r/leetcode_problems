impl Solution {
    pub fn max_sub_array(nums: Vec<i32>) -> i32 {
        let (mut sum, mut max) = (0, nums[0]);
        for i in 0..nums.len() {
            sum += nums[i];
            if sum > max {
                max=sum;
            }
            if sum < 0 {
                sum = 0;
            }
        }
        max
    }
}
