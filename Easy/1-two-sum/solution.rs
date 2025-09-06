//leetcode.com/problems/two-sum/
use std::collections::HashMap;
impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut s: HashMap<i32, i32> = HashMap::new();
        for (index, num) in nums.iter().enumerate() {
            let val = target - *num;
            if s.contains_key(&val) {
                return vec![s[&val], index as i32];
            }
            s.insert(*num, index as i32);
        }
        Vec::new()
    }
}
