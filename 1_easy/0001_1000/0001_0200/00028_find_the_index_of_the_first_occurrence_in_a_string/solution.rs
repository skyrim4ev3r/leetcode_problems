impl Solution {
    pub fn str_str(haystack: String, needle: String) -> i32 {

        let needle_bytes = needle.into_bytes();
        let needle_bytes_len = needle_bytes.len();

        haystack.into_bytes().windows(needle_bytes_len).position(|window| window == needle_bytes).map_or(-1, |pos| pos as i32)
    }
}
