impl Solution {
    fn generate_strings_backtrack(res: &mut Vec<String>, curr: &mut Vec<u8>, len: usize) {
        if curr.len() == len {
            res.push(String::from_utf8(curr.clone()).unwrap());
            return;
        }

        if curr.is_empty() || *curr.last().unwrap() == b'1' {
            curr.push(b'0');
            Self::generate_strings_backtrack(res, curr, len);
            curr.pop();
        }

        curr.push(b'1');
        Self::generate_strings_backtrack(res, curr, len);
        curr.pop();
    }

    pub fn valid_strings(n: i32) -> Vec<String> {
        let mut res: Vec<String> = Vec::new();
        let mut curr: Vec<u8> = Vec::new();
        Self::generate_strings_backtrack(&mut res, &mut curr, n as usize);

        res
    }
}
