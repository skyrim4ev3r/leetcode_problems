impl Solution {
    pub fn count_subarrays(nums: Vec<i32>, k: i64) -> i64 {

        let mut count = 0_i64;
        let mut total_sum = 0_i64;
        let mut left = 0_usize;
        let mut right = 0_usize;
        let nums_len = nums.len();

        loop {
            while left < nums_len && nums[left] as i64 >= k {
                left += 1;
            }

            if left >= nums_len {
                break;
            }

            right = left;
            total_sum = 0_i64;

            while left <= right {
                while right <  nums_len && ((total_sum + nums[right] as i64) * (right - left + 1) as i64) < k {
                    total_sum += nums[right] as i64;
                    right += 1;
                }

                if right == nums_len || nums[right] as i64 >= k {
                    count += ((right - left) as i64 * (right - left + 1) as i64) / 2;
                    left = right;
                    break;
                }

                count += (right - left) as i64;
                total_sum -= nums[left] as i64;
                left += 1;
            }
        }

        count
    }
}
