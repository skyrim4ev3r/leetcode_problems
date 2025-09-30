use std::collections::HashMap;

impl Solution {
    pub fn count_good_rectangles(rectangles: Vec<Vec<i32>>) -> i32 {
        let mut counter_map: HashMap<i32, i32> = HashMap::new();
        let mut max_len = -1;
        for rec in rectangles.into_iter() {
            let curr_len = rec[0].min(rec[1]);
            if max_len <= curr_len {
                max_len = curr_len;
                *counter_map.entry(max_len).or_insert(0) += 1;
            }
        }
        
        counter_map[&max_len]
    }
}
