impl Solution {
    pub fn remove_duplicates(nums: &mut Vec<i32>) -> i32 {
        let nums_len = nums.len();

        if nums_len < 3 {
            return nums_len as i32;
        }

        let mut curr_len = 2_usize;

        for i in 2..nums_len {
            if nums[i] == nums[curr_len - 2] {
                continue;
            }

            nums[curr_len] = nums[i];
            curr_len += 1;
        }

        curr_len as i32
    }
}
