impl Solution {
    pub fn three_sum(mut nums: Vec<i32>) -> Vec<Vec<i32>> {
        nums.sort();
        let mut res: Vec<Vec<i32>> = Vec::new();
        let mut size = nums.len() - 1;
        for i in 0..nums.len() {
            if nums[i]>0 {
                break;
            }
            if (i>0 && nums[i]==nums[i-1]) || ((nums[i]*-1)>nums[size]*2) {
                continue;
            }
            while nums[size]>0 && (nums[i]*-1)*2 < nums[size] {  
                size -= 1; 
            }
            let mut k = size;
            let mut j = i+1;
            while j < k {
                let mut sum = nums[i] + nums[j] + nums[k];
                if sum < 0 {
                    j += 1;
                } else if sum > 0 {
                    k -= 1;
                } else {
                    res.push(vec![nums[i],nums[j],nums[k]]);
                    loop {
                        j += 1;
                        if !(j < nums.len()-1 && nums[j]==nums[j-1]) {
                            break;
                        }
                    }
                    loop {
                        k -= 1;
                        if !(k>0 && nums[k]==nums[k+1]) {
                            break;
                        }
                    }                  
                }
            } 
        }
        return res;
    }
}
