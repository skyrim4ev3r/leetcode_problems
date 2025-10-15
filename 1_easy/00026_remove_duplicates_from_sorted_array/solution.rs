impl Solution {
    pub fn remove_duplicates(nums: &mut Vec<i32>) -> i32 {

        let nums_len = nums.len();
        let mut index = 0_usize;

        for i in 1..nums_len {
            if nums[i] != nums[i - 1] {
                index += 1;
                nums[index] = nums[i];
            }
        }

        index as i32 + 1
    }
}
