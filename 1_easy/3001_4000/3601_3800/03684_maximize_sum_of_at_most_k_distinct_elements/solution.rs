use std::collections::BTreeSet;
impl Solution {
    pub fn max_k_distinct(nums: Vec<i32>, k: i32) -> Vec<i32> {        
        let mut exact_set: BTreeSet<i32> = BTreeSet::new();
        exact_set.extend(nums);
        exact_set.into_iter().rev().take(k as usize).collect::<Vec<i32>>()
    }
}
