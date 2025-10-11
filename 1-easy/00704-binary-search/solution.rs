impl Solution {
    pub fn search(nums: Vec<i32>, target: i32) -> i32 {

        let pos = nums.binary_search(& target).unwrap_or_else(|x| x);

        if pos == nums.len() || nums[pos] != target {
            return -1;
        }

        pos as i32
    }
}
