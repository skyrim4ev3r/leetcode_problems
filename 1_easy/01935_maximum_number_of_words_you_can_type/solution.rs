use std::collections::HashSet;
impl Solution {
    pub fn can_be_typed_words(text: String, broken_letters: String) -> i32 {

        let mut broken_letters_set: HashSet<u8> = HashSet::new();
        broken_letters_set.extend(broken_letters.into_bytes().iter().cloned());

        let mut count = 0;

        for word in text.split_whitespace()  {

            let mut had_broken_char = false;
            let word_bytes = word.as_bytes();
            for byte in word_bytes {
                if broken_letters_set.contains(byte) {
                    had_broken_char = true;
                    break;
                }
            }

            if !had_broken_char {
                count += 1;
            }
        }

        count
    }
}
