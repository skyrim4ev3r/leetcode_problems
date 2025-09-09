impl Solution {
    pub fn find_content_children(mut g: Vec<i32>, mut s: Vec<i32>) -> i32 {
        let (mut i, mut j, mut count) = (0usize, 0usize, 0i32);
        s.sort();
        g.sort();
        while  i < s.len() && j < g.len() {
            if(g[j] <= s[i]) {
                count += 1;
                j += 1;
            }
            i += 1;
        }
        count
    }
}
