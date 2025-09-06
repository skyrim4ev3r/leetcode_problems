impl Solution {
    pub fn is_trionic(nums: Vec<i32>) -> bool {
        let (mut is_increase, mut change_state_count, mut ret_false_cond) = (true, 0u8, nums[0] >= nums[1]);
        for i in 1..nums.len() {
            if nums[i] == nums[i-1] || ret_false_cond {
                return false;
            } else if is_increase != (nums[i-1] < nums[i]) {
                is_increase = !is_increase;
                change_state_count += 1;
                ret_false_cond = change_state_count > 2;
            }
        }
        change_state_count == 2        
    }
}