impl Solution {
    fn solve(pos: usize, s: & Vec<u8>, mem: &mut Vec<i32>) -> i32 {
        if pos == s.len() {
            1
        } else if mem[pos] > -1 {
            mem[pos]
        } else if s[pos] == b'0' {
            mem[pos] = 0;
            0
        } else {

            let mut res = Self::solve(pos+1, s, mem);
            if pos < s.len() - 1 && (s[pos] == b'1' || (s[pos] == b'2' && s[pos+1] < b'7')) {
                res += Self::solve(pos+2, s, mem);
            }
            mem[pos] = res;
            res
        }
    }

    pub fn num_decodings(mut s: String) -> i32 {
        let s = s.into_bytes();
        let mut mem = vec![-1i32; s.len()];
        Self::solve(0, & s, &mut mem)
    }
}
