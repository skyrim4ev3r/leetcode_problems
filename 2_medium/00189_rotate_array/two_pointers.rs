impl Solution {
    pub fn rotate(nums: &mut Vec<i32>, k: i32) {
        let len = nums.len();
        let k = k as usize % len;

        let mut left = 0_usize;
        let mut right = len - k - 1;

        while left < right {
            let temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
            left += 1;
            right -= 1;
        }

        left = len - k;
        right = len - 1;

        while left < right {
            let temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
            left += 1;
            right -= 1;
        }

        nums.reverse();
    }
}
