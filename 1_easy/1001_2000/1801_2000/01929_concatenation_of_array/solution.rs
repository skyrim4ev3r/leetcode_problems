impl Solution {
    pub fn get_concatenation(mut nums: Vec<i32>) -> Vec<i32> {
        nums.extend(nums.clone());
        nums
    }
}
