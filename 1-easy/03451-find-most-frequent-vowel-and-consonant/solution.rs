impl Solution {
    pub fn max_freq_sum(mut s: String) -> i32 {
        
        const ALPHABET_LEN: usize = 26;
        let mut frequencies = [0; ALPHABET_LEN];
        for ch in s.into_bytes() {
            frequencies[(ch - b'a') as usize] += 1;
        }

        let mut max_frequency_vowels = 0;
        let mut max_frequency_consonants = 0;
        for i in 0..ALPHABET_LEN {

            if (i == 0 || i == 4 || i == 8 || i == 14 || i == 20){// 'a', 'e', 'i', 'o', 'u'
                max_frequency_vowels = max_frequency_vowels.max(frequencies[i]);
            } else {
                max_frequency_consonants = max_frequency_consonants.max(frequencies[i]);
            }
        }

        max_frequency_consonants + max_frequency_vowels
    }
}
