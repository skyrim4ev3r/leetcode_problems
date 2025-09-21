use std::collections::HashSet;

impl Solution {
    pub fn partition_string(s: String) -> Vec<String> {
        let mut seen = HashSet::<&[u8]>::new();
        let mut result = Vec::<String>::new();
        let mut left = 0usize;
        let mut right = 0usize;
        let bytes = s.into_bytes();

        while right < bytes.len() {
            let slice = &bytes[left..=right];
            if seen.insert(slice) {
                result.push(String::from_utf8_lossy(slice).into_owned());
                left = right + 1;
                right = left; 
            } else {
                right += 1; 
            }
        }

        result
    }
}
