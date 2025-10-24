impl Solution {
    pub fn plus_one(mut digits: Vec<i32>) -> Vec<i32> {

        let mut offset = 1;
        let digits_len = digits.len();

        for i in (0..digits_len).rev() {
            digits[i] += offset;
            offset = 0;
            if digits[i] > 9 {
                digits[i] -= 10;
                offset = 1;
            } else {
                break;
            }
        }

        if offset == 1 {
            digits.push(0);
            digits[0] = 1;
        }

        digits
    }
}
