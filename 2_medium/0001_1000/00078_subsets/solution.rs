impl Solution {
    fn subsets_recursive(nums: & Vec<i32>, res: &mut Vec<Vec<i32>>, curr_vec: &mut Vec<i32>, start_index: usize) {
        for i in start_index..nums.len() {
            curr_vec.push(nums[i]);
            res.push(curr_vec.clone());
            Self::subsets_recursive(nums, res, curr_vec, i + 1);
            curr_vec.pop();
        }

    }
    pub fn subsets(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut res: Vec<Vec<i32>> = Vec::new();
        let mut tmp_vec: Vec<i32> = Vec::new();
        res.push(Vec::new());
        Self::subsets_recursive(& nums, &mut res, &mut tmp_vec, 0);

        res
    }
}
