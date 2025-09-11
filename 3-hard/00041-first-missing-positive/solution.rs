impl Solution {
    pub fn first_missing_positive(nums: Vec<i32>) -> i32 {
        let n = nums.len() as i32;

        // at worst case if vector of len n contains 1..n then we need n+1 space
        // that extra space is pos[0] and it will get ignore to easily map valid nums to thier index
        let mut pos = vec![false;n as usize + 1];

        for num in nums {

            // we can ignore numers greather than n, because if ther be any then at least some int between 1..n is missed
            if num > 0 && num <= n {
                pos[num as usize] = true;
            }

        }

        // start from 1, ignoring pos[0]
        for i in 1..=(n as usize) {

            // if any num in nums be "greater than n" or "less than one" then at least there is at least one "i where pos[i] = false" 
            if pos[i] == false {
                return i as i32;
            }
        }
        n + 1//this happens at worst case when vector of len n have 1..n values
    }
}
