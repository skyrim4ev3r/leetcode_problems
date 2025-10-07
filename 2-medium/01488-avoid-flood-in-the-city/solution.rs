use std::collections::{BTreeSet, HashMap};

impl Solution {
    pub fn avoid_flood(rains: Vec<i32>) -> Vec<i32> {

        let rains_len = rains.len();

        let mut lake_last_rainy_day: HashMap<i32, usize> = HashMap::new();
        let mut dry_days: BTreeSet<usize> = BTreeSet::new();
        let mut res: Vec<i32> = Vec::with_capacity(rains_len);

        for day in 0..rains_len {
            if (rains[day] == 0) {
                res.push(1);
                dry_days.insert(day);
            } else {
                res.push(-1);
                let lake = rains[day];
                if let Some(last_rainy_day_on_this_lake) = lake_last_rainy_day.insert(lake, day) {
                    if let Some(&avaiable_day) = dry_days.range(last_rainy_day_on_this_lake..).next() {
                        res[avaiable_day] = lake;
                        dry_days.remove(&avaiable_day);
                    } else {
                        return Vec::new();
                    }
                }
            }
        }

        res
    }
}
