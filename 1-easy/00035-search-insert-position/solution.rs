impl Solution {
    pub fn search_insert(nums: Vec<i32>, target: i32) -> i32 {
        let (mut left, mut right) = (0isize, nums.len() as isize - 1);
        while left <= right {
            let mid = (right + left) / 2;
            if nums[mid as usize] >= target {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        left as i32
    }
}
