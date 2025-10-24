impl Solution {
    pub fn triangular_sum(mut nums: Vec<i32>) -> i32 {
        while nums.len() != 1 {
            for i in 0..(nums.len() - 1) {
                nums[i] += nums[i + 1];
                if nums[i] >= 10 {
                    nums[i] -= 10;
                }
            }
            nums.pop();
        }

        nums[0]
    }
}
