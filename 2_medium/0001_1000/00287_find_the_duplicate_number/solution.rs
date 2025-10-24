impl Solution {
    pub fn find_duplicate(mut nums: Vec<i32>) -> i32 {

        let mut num = 0;

        for i in 0..nums.len() {
            num = nums[i].abs();
            if nums[num as usize] > 0 {
                nums[num as usize] *= -1;
            } else {
                break;
            }
        }

        for i in 0..nums.len() {
            if nums[i] < 0 {
                nums[i] *= -1;
            }
        }

        num
    }
}
