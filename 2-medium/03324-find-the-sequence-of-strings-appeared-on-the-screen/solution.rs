impl Solution {
    pub fn string_sequence(target: String) -> Vec<String> {
        let target_bytes = target.into_bytes();
        let mut screen: Vec<u8> = Vec::with_capacity(target_bytes.len());
        let mut res: Vec<String> = Vec::new();
        let mut index = 0_usize;
        while screen != target_bytes {
            if screen.len() == 0 || screen[index] == target_bytes[index] {
                screen.push(b'a');
                index = screen.len() - 1;
            } else {
                screen[index] += 1;
            }

            res.push(String::from_utf8_lossy(& screen).to_string());
        }

        res
    }
}
