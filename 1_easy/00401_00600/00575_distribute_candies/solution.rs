use std::collections::HashSet;

impl Solution {
    pub fn distribute_candies(candy_type: Vec<i32>) -> i32 {
        let n = candy_type.len();
        let mut candy_set: HashSet<i32> = HashSet::new();
        for candy in candy_type.into_iter() {
            candy_set.insert(candy);
        }

        ((n / 2).min(candy_set.len())) as i32
    }
}
