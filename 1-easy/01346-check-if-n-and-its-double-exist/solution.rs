use std::collections::HashSet;

impl Solution {
    pub fn check_if_exist(arr: Vec<i32>) -> bool {
        let mut set: HashSet<i32> = HashSet::new();

        for num in arr.into_iter() {
            let double_num = num * 2;
            if set.contains(&double_num) {
                return true;
            }

            if (num & 1) != 1 {
                let half = num / 2;
                if set.contains(&half) {
                    return true;
                }
            }

            set.insert(num);
        }

        return false;
    }
}
