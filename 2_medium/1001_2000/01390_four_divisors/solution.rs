impl Solution {
    pub fn sum_four_divisors(nums: Vec<i32>) -> i32 {
        let mut res = 0;
        for num in nums {
        
            let sq = (num as f64).sqrt() as i32;
            
            // if this condition be true then number of divisors are odd and cant be 4
            if sq*sq == num {
                continue;
            }
            
            
            // 1 and num are two divisors of num
            // so we start from count=2 and sum =1+num
            let mut count = 2;
            let mut sum = 1 + num;
            for i in 2..=sq {
                if num % i == 0 {
                    sum += i + num / i;
                    count += 2;
                    if count > 4 {
                        break;
                    }
                }
            }
            
            if count == 4 {
                res += sum;
            }
            
        }
        res
    }
}
