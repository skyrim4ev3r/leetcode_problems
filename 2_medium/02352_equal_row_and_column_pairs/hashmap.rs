use std::collections::HashMap;

impl Solution {
    pub fn equal_pairs(grid: Vec<Vec<i32>>) -> i32 {
        let n = grid.len();
        let mut hashmap: HashMap<Vec<i32>, i32> = HashMap::new();

        for j in 0..n {
            let mut temp: Vec<i32> = Vec::with_capacity(n);

            for i in 0..n {
                temp.push(grid[i][j]);
            }

            *hashmap.entry(temp).or_insert(0) += 1;
        }

        let mut count = 0_i32;

        for row in grid.into_iter() {
            if let Some(val) = hashmap.get(&row) {
                count += *val;
            }
        }

        count
    }
}
