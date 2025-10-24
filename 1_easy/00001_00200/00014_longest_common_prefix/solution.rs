impl Solution {
    pub fn longest_common_prefix(strs: Vec<String>) -> String {

        let mut min_string_len = usize::MAX;
        let strs_len = strs.len();
        let mut strs_bytes: Vec<Vec<u8>> = Vec::with_capacity(strs_len);
        let mut res: Vec<u8> = Vec::new();

        for s in strs.into_iter() {
            let s_bytes = s.into_bytes();
            min_string_len = min_string_len.min(s_bytes.len());
            strs_bytes.push(s_bytes);
        }

        for j in 0..min_string_len {

            for i in 1..strs_len {
                if strs_bytes[i][j] != strs_bytes[i - 1][j] {
                    return String::from_utf8(res).unwrap();
                }
            }

            res.push(strs_bytes[0][j]);
        }

        String::from_utf8(res).unwrap()
    }
}
