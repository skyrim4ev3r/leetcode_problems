impl Solution {

    //checks if given char is vowel
    fn is_vowel(ch: u8) -> bool {
        matches!(ch, b'a' | b'e' | b'i' | b'o' | b'u' | b'A' | b'E' | b'I' | b'O' | b'U')
    }

    pub fn sort_vowels(mut s: String) -> String {
        //changing string into vector
        let mut s = s.into_bytes();

        //inserting all vowel chars of current string into vector
        let mut vowels: Vec<u8> = s.iter().filter(|&&ch| Self::is_vowel(ch)).cloned().collect();
        vowels.sort(); // then sorting that vector
        
        //now for every vowel in s, we replace it with char in sorted vowels array
        let mut vowel_index = 0usize;
        for i in 0..s.len() {
            if Self::is_vowel(s[i]) {
                s[i] = vowels[vowel_index];
                vowel_index += 1;
            }
        }
        
        String::from_utf8(s).expect("")
    }
}
