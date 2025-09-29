impl Solution {
    pub fn maximize_sum(nums: Vec<i32>, k: i32) -> i32 {
        let mut max = i32::MIN;
        nums.into_iter().for_each(|num| max = max.max(num));

        max * k + (k * (k - 1)) / 2
    }
}
