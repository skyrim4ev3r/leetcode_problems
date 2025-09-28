impl Solution {
    fn remove_occurrences_helper(s_bytes: &mut Vec<u8>, part_bytes: & Vec<u8>) -> bool {
        let mut left = 0_usize;
        let mut right = part_bytes.len() - 1;

        while right < s_bytes.len() {
            let window: &[u8] = & s_bytes[left..=right];
            if window == part_bytes {
                let mut res: Vec<u8> = Vec::new();
                res.extend(&s_bytes[0..left]);
                res.extend(&s_bytes[right + 1..]);
                *s_bytes = res;
                return true;
            }
            right += 1;
            left += 1;
        }

        false
    }

    pub fn remove_occurrences(s: String, part: String) -> String {
        let mut s_bytes = s.into_bytes();
        let part_bytes = part.into_bytes();
        
        while Self::remove_occurrences_helper(&mut s_bytes, &part_bytes) {}

        String::from_utf8(s_bytes).unwrap()
    }
}
