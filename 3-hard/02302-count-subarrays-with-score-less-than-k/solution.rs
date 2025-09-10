impl Solution {
    pub fn count_subarrays(nums: Vec<i32>, k: i64) -> i64 {
        let (mut count, mut total_sum, mut left, mut right) = (0i64, 0i64, 0usize, 0usize);
        loop {
            while left != nums.len() && nums[left] as i64 >= k {
                left += 1;
            }
            if left == nums.len() {
                break;
            }
            right = left;
            total_sum = nums[left] as i64;
            while right >= left {
                while right <  nums.len() - 1 && ((total_sum + nums[right + 1] as i64) * (right - left + 2) as i64) < k {
                    right += 1;
                    total_sum += nums[right] as i64;
                }
                if right == nums.len() - 1 || nums[right+1] as i64 >= k {
                    count += ((right - left + 1) as i64 * (right - left + 2) as i64) / 2;
                    left = right + 1;
                    break;
                }
                count += (right - left + 1) as i64;
                total_sum -= nums[left] as i64;
                left += 1;
            }
        }
        count
    }
}
