impl Solution {
    pub fn number_of_beams(bank: Vec<String>) -> i32 {
        let mut stack: Vec<i32> = Vec::new();
        for row in bank.into_iter() {
            let mut count = 0;
            for byte in row.into_bytes() {
                if byte == b'1' {
                    count += 1;
                }
            }

            if count > 0 {
                stack.push(count);
            }
        }

        let mut res = 0;
        if !stack.is_empty() {
            for i in (1..stack.len()).rev() {
                res += stack[i] * stack[i - 1];
            }
        }

        res
    }
}
