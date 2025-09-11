impl Solution {
    pub fn max_sub_array(nums: Vec<i32>) -> i32 {
    
        let (mut sum, mut max) = (0, nums[0]);
        
        for i in 0..nums.len() {
        
            sum += nums[i];
            
            if sum > max {
                max=sum;
            }
            
            //because of this: then starting point can never be negative, so if 
            //sum of some "positive_start_point" up to "some negative_ending_point" be negative then
            //none of subarrays of that subaray cant be positive when they ""include"" ==> "negative_ending_point"
            //because even with help of our positive_starting point it cant get positive
            //so we can start to sum elements again!
            if sum < 0 {
                sum = 0;
            }
        }
        
        max
    }
}
