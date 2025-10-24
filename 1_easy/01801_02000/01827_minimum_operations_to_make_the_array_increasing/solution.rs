impl Solution {
    pub fn min_operations(mut nums: Vec<i32>) -> i32 {
        let mut count = 0;
        for i in 1..nums.len() {
            if nums[i - 1] >= nums[i] {
                let amount_to_add = nums[i - 1] - nums[i] + 1;
                count += amount_to_add;
                nums[i] += amount_to_add;
            }
        }

        count
    }
}
