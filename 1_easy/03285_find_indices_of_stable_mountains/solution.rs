impl Solution {
    pub fn stable_mountains(height: Vec<i32>, threshold: i32) -> Vec<i32> {
        let mut res: Vec<i32> = Vec::new();
        for i in 0..height.len()-1 {
            if height[i] > threshold {
                res.push(i as i32 + 1);
            }
        }

        res
    }
}
