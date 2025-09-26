impl Solution {
    pub fn triangle_number(mut nums: Vec<i32>) -> i32 {
        nums.sort();
        let mut sum = 0;
        for i in 2..nums.len() {
            let mut left = 0;
            let mut right = i - 1;
            while (left < right) {
                if (nums[left] + nums[right] > nums[i]) {
                    sum += (right - left) as i32;
                    right -= 1;
                } else {
                    left += 1;
                }
            }
        }

        sum
    }
}
