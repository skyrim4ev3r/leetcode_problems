impl Solution {
    pub fn min_deletion_size(strs: Vec<String>) -> i32 {
        let mut strs_bytes: Vec<Vec<u8>> = Vec::with_capacity(strs.len());
        for s in strs.into_iter() {
            strs_bytes.push(s.into_bytes());
        }

        let rows = strs_bytes.len();
        let cols = strs_bytes[0].len();
        let mut count = 0;

        for j in 0..cols {

            let mut is_sorted = true;
            for i in 1..rows {
                if strs_bytes[i][j] < strs_bytes[i - 1][j] {
                    is_sorted = false;
                    break;
                }
            }

            if !is_sorted {
                count += 1;
            }
        }

        count
    }
}
