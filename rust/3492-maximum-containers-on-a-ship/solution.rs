//https://leetcode.com/problems/maximum-containers-on-a-ship/description/
impl Solution {
    pub fn max_containers(n: i32, w: i32, max_weight: i32) -> i32 {
        std::cmp::min(max_weight / w, n*n)
    }
}
