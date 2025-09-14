impl Solution {
    pub fn merge(mut intervals: Vec<Vec<i32>>) -> Vec<Vec<i32>> {

        let mut res: Vec<Vec<i32>> = Vec::new();

        intervals.sort_by(|a, b| a[0].cmp(&b[0]));

        let mut index = 0;
        while index != intervals.len() {

            let mut right = index + 1;
            let mut tmp_vec = intervals[index].clone();
            while right != intervals.len() && intervals[right][0] <=  tmp_vec[1] {
                tmp_vec[1] = tmp_vec[1].max(intervals[right][1]);
                right += 1;
            }
            res.push(tmp_vec);

            index = right;
        }

        res
    }
}
