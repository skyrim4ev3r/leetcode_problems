impl Solution {
    pub fn remove_element(nums: &mut Vec<i32>, val: i32) -> i32 {

        let mut len = nums.len();
        let mut k = 0_usize;

        for i in 0..len {
            if nums[i] != val {
                nums[k] = nums[i];
                k += 1;
            }
        }

        k as i32
    }
}
