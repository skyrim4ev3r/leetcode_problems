impl Solution {
    pub fn height_checker(heights: Vec<i32>) -> i32 {

        let mut heights_clone = heights.clone();
        let mut count = 0_i32;
        let len = heights.len();

        heights_clone.sort_unstable();

        for i in 0..len {
            if heights[i] != heights_clone[i] {
                count += 1;
            }
        }

        count
    }
}
