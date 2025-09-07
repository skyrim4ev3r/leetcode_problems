impl Solution {
    pub fn reverse_degree(s: String) -> i32 {
        let mut sum = 0;
        let z = ('z' as u8)+1;
        let ss = s.as_bytes();
        for i in 0..ss.len() {
            let t = (z - ss[i]) as i32;
            sum += t * ((i+1) as i32); 
        }
        sum
    }
}