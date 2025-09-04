//leetcode.com/problems/check-if-any-element-has-prime-frequency/description/
use std::collections::HashMap;
impl Solution {
    pub fn check_prime_frequency(nums: Vec<i32>) -> bool {
        let mut res: HashMap<i32, i32> = HashMap::new();
        nums.iter().for_each(|item| {res.entry(*item).and_modify(|value| *value = (*value) + 1).or_insert(1);});
        res.iter().any(|(_,&val)| val >1 && !((2..=(val as f64).sqrt() as i32).clone().any(|item| val % item == 0)))
    }
}

//just for this problem
impl SolutionOptimized {
    pub fn check_prime_frequency(nums: Vec<i32>) -> bool {
        let primes_arr = [false,false,true,true,false,true,false,true,false,false,false,true,false,true,false,false,false,true,false,true,false,false,false,true,false,false,false,false,false,true,false,true,false,false,false,false,false,true,false,false,false,true,false,true,false,false,false,true,false,false,false,false,false,true,false,false,false,false,false,true,false,true,false,false,false,false,false,true,false,false,false,true,false,true,false,false,false,false,false,true,false,false,false,true,false,false,false,false,false,true,false,false,false,false,false,false,false,true,false,false,false];
        let mut freqs= [0u8;101];
        nums.iter().for_each(|item| freqs[*item as usize] +=1 );
        freqs.iter().any(|item| primes_arr[*item as usize])
    }
}
