impl Solution {
    pub fn smallest_index(nums: Vec<i32>) -> i32 {
        let condition = |mut index: i32, mut value: i32| {
            while value > 0 {
                index -= value%10;
                value/=10;
            }
            index == 0
        };
        if let Some((index, value)) = nums.iter().enumerate().find(|&(i, &v)| condition(i as i32, v)) {
            index as i32
        } else {
            -1
        }
    }
}