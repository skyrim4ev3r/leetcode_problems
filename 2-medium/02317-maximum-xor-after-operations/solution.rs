impl Solution {
    pub fn maximum_xor(nums: Vec<i32>) -> i32 {
        let mut res = 0;
        nums.into_iter().for_each(|num| res |= num);

        res
    }
}
