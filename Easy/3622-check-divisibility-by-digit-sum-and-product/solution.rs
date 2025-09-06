impl Solution {
    pub fn check_divisibility(n: i32) -> bool {
        let (mut x, mut sum, mut mul) = (n, 0, 1);
        while x > 0 {
            let tmp = x % 10;
            sum += tmp;
            mul *= tmp;
            x /= 10;
        }
        n % (sum + mul) == 0
    }
}