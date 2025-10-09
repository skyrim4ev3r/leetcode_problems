impl Solution {
    pub fn maximum69_number (mut num: i32) -> i32 {
        let mut digits: Vec<i32> = Vec::new();

        while num > 0 {
            digits.push(num % 10);
            num /= 10;
        }

        let mut res = 0_i32;
        let mut can_change = true;

        while let Some(digit) = digits.pop() {    
            res *= 10;
            if can_change && digit == 6 {
                can_change = false;
                res += 9;
            } else {
                res += digit;
            }
        }

        res
    }
}
