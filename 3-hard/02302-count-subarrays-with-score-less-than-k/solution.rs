impl Solution {
    pub fn count_subarrays(nums: Vec<i32>, k: i64) -> i64 {
    
        let (mut count, mut total_sum, mut left, mut right) = (0i64, 0i64, 0usize, 0usize);
        
        loop {
        
            while left != nums.len() && nums[left] as i64 >= k {
                left += 1;
            }
            
            //if we reach to end of vector then we cant have any more starting point
            if left == nums.len() {
                break;
            }
            
            //starting point: from left location
            right = left;
            total_sum = nums[left] as i64; //we have only this current number in our answer
            while right >= left {
            
                while right <  nums.len() - 1 && ((total_sum + nums[right + 1] as i64) * (right - left + 2) as i64) < k {
                    right += 1;
                    total_sum += nums[right] as i64;
                }
                
                //if right reach "len-1" or next element is that big that cant add to our solution
                //then using math to calc all possible sub array in this range
                if right == nums.len() - 1 || nums[right+1] as i64 >= k {
                
                    //if right reach "len-1" then this will set left to "len" ==> and mian loop will break at ==> if (left == nums.size())
                    //if right is not "len-1" then left will be set to that big number index which cant be include in our solution, and it will go
                    //  forward untill it find another starting point or reach to end of array
                    
                    count += ((right - left + 1) as i64 * (right - left + 2) as i64) / 2;
                    left = right + 1;
                    break;
                }
                
                //if next number after right index is not that big and can be get include in our final answer
                //but its not that small to get include with our current left index then
                //we will add all possible subarrays for only "left" index, and push left forward
                //so at begging of loop right will try to push forward and add that number aswell
                count += (right - left + 1) as i64;
                
                //left index value should no more be included in our final answer
                total_sum -= nums[left] as i64;
                
                //push left forward
                left += 1;
            }
        }
        count
    }
}
