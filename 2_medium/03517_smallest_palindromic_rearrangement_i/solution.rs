impl Solution {
    pub fn smallest_palindrome(mut s: String) -> String {       
        let mut s = s.into_bytes();
        let mut freq = [0i32;26];

        s.iter().for_each(|&ch| freq[(ch - b'a') as usize] += 1);

        let mut l = 0;
        let mut r = s.len() - 1;

        for i in 0..freq.len() {

            if (freq[i] & 1) == 1 {
                let mid = s.len() / 2;
                s[mid] = i as u8 + b'a';
            }

            for j in 0..freq[i]/2 {
                s[l] = i as u8 + b'a';
                s[r] = i as u8 + b'a';
                l += 1;
                r -= 1;
            }
        }

        String::from_utf8(s).unwrap()
    }
}
