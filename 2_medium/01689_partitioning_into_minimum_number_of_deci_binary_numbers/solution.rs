impl Solution {
    pub fn min_partitions(n: String) -> i32 {
        (n.into_bytes().into_iter().fold(b'0', |max_char, ch| max_char.max(ch)) - b'0') as i32
    }
}
