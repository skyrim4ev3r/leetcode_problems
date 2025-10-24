impl Solution {
    pub fn add_binary(a: String, b: String) -> String {

        let mut offset = 0_u8;
        let mut a_bytes = a.into_bytes();
        let mut b_bytes = b.into_bytes();

        if a_bytes.len() < b_bytes.len() {
            std::mem::swap(&mut a_bytes, &mut b_bytes);
        }

        let mut a_bytes_len = a_bytes.len();

        for i in (0..a_bytes_len).rev() {

            let mut b_byte = b'0';

            if let Some(byte) = b_bytes.pop() {
                b_byte = byte;
            }

            let mut byte_sum = (a_bytes[i] - b'0') + (b_byte - b'0') + offset;
            offset = 0;
            if byte_sum > 1 {
                byte_sum -= 2;
                offset = 1;
            }

            a_bytes[i] = byte_sum + b'0';

            if offset == 0 && b_bytes.is_empty() {
                break;
            }
        }

        if offset == 1 {
            a_bytes.insert(0_usize, b'1');
        }

        String::from_utf8(a_bytes).unwrap()
    }
}
