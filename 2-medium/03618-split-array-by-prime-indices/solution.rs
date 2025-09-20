impl Solution {
    fn is_prime(n: usize, primes: &[usize]) -> bool {
        if n < 2 {
            return false;
        }
        
        if n == 2 || n == 3 || n == 5 {
            return true;
        }

        if n % 2 == 0 || n % 3 == 0 || n % 5 == 0 {
            return false;
        }

        let sqrt = (n as f64).sqrt() as usize;
        for i in 0..primes.len() {
            if primes[i] > sqrt { //n is prime and not divisable by all primes between 2..sqrt
                return true;
            }
            if n % primes[i] == 0 {
                return false;
            }
        }

        true
    }

    pub fn split_array(nums: Vec<i32>) -> i64 {
        let mut sum = 0i64;

        // pre calculated prime for sqrt of max possible len => sqrt(10_000)
        let primes = [2usize, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67,
                     71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151,
                    157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239,
                    241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313];

        for i in 0..nums.len() {
            if Self::is_prime(i, &primes) {
                sum += nums[i] as i64;
            } else {
                sum -= nums[i] as i64;
            }
        }

        sum.abs()
    }
}
