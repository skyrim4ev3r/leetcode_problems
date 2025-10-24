impl Solution {
    pub fn get_no_zero_integers(n: i32) -> Vec<i32> {
        for i in 1..n {
            let nums = [i,n-i];
            let mut is_valid = true;
            for mut a in nums {
                if ! is_valid {
                    break;
                }
                while a > 0 {
                    if a % 10 == 0 {
                        is_valid = false;
                        break;
                    }
                    a /= 10;
                }
            }
            if is_valid {
                return vec![i, n-i];
            }
        }
        Vec::new()
    }
}
