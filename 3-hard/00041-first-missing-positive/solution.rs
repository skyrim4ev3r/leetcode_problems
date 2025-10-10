impl Solution {
    pub fn first_missing_positive(mut nums: Vec<i32>) -> i32 {

        let n = nums.len();

        for i in 0..n {
            if nums[i] <= 0 {
                nums[i] = i32::MAX;
            }
        }

        for i in 0..n {
            let num = (nums[i].abs() - 1) as usize;
            if num < n {
                if nums[num] > 0 {
                    nums[num] *= -1;
                }
            }
        }

        for i in 0..n {
            if nums[i] > 0{
                return i as i32 + 1;
            }
        }

        n as i32 + 1
    }
}
