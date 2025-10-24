impl Solution {
    pub fn can_see_persons_count(heights: Vec<i32>) -> Vec<i32> {

        let mut res: Vec<i32> = vec![0; heights.len()];
        let mut stack: Vec::<i32> = Vec::new();

        for i in (0..heights.len()).rev() {
            while let Some(val) = stack.last() {
                res[i] += 1;
                if *val <= heights[i] {
                    stack.pop();
                } else {
                    break;
                }
            }
            stack.push(heights[i]);
        }

        res
    }
}
