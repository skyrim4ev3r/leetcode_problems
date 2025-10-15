use std::collections::HashSet;

impl Solution {
    pub fn find_the_prefix_common_array(a: Vec<i32>, b: Vec<i32>) -> Vec<i32> {
        let mut set: HashSet<i32> = HashSet::new();
        let mut res:  Vec<i32> = Vec::with_capacity(a.len());
        let mut common = 0;
        for i in 0..a.len() {
            if set.contains(&a[i]) {
                set.remove(&a[i]);
                common += 1;
            } else {
                set.insert(a[i]);
            }

            if set.contains(&b[i]) {
                set.remove(&b[i]);
                common += 1;
            } else {
                set.insert(b[i]);
            }

            res.push(common);
        }

        res
    }
}
