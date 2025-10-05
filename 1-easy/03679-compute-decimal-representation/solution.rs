impl Solution {
    pub fn decimal_representation(mut n: i32) -> Vec<i32> {

        let mut multiplier = 1;
        let mut res: Vec<i32> = Vec::new();

        while n > 0 {
            let tmp = (n % 10) * multiplier;

            if tmp != 0 {
                res.push(tmp);
            }

            multiplier *= 10;
            n /= 10;
        }

        res.reverse();

        res
    }
}
