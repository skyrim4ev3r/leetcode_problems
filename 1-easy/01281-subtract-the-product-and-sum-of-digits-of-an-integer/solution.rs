impl Solution {
    pub fn subtract_product_and_sum(mut n: i32) -> i32 {
        let mut sum = 0;
        let mut mul = 1;
        while n > 0 {
            let tmp = n % 10;
            mul *= tmp;
            sum += tmp;
            n /= 10;
        }

        mul - sum
    }
}
