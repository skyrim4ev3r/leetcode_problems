use std::cmp::Ordering;

impl Solution {
    pub fn search_range(nums: Vec<i32>, target: i32) -> Vec<i32> {

        let l = nums.binary_search_by(|num| match num.cmp(&target) {
            Ordering::Less => Ordering::Less,
            _ => Ordering::Greater,
        }).unwrap_or_else(|x| x);

        if l == nums.len() || nums[l] != target {
            return vec![-1, -1];
        }

        let r = nums.binary_search_by(|num| match num.cmp(&target) {
            Ordering::Less | Ordering::Equal => Ordering::Less,
            Ordering::Greater => Ordering::Greater,
        }).unwrap_or_else(|x| x) - 1;

        vec![l as i32, r as i32]
    }
}
