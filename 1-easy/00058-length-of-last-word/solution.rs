impl Solution {
    pub fn length_of_last_word(s: String) -> i32 {

        let mut s_bytes = s.into_bytes();
        let mut count = 0_i32;
        let mut is_counting_started = false;
    
        while let Some(byte) = s_bytes.pop() {
            if byte != b' ' {
                is_counting_started = true;
            }

            if is_counting_started {
                if byte != b' ' {
                    count += 1;
                } else {
                    break;
                }
            }
        }

        count
    }
}
