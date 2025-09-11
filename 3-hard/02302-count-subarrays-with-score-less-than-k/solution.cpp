class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
    
        long long max{0}, sum{0}, left{0}, right{0};
        
        while (true) {
        
            //skip all left indeces that cant be anwer
            while (left != nums.size() && nums[left] >= k) {
                ++left;
            }
            
            //if we reach to end of vector then we cant have any more starting point
            if (left == nums.size()) {
                break;
            }
            
            //starting point: from left location
            right = left;
            sum = nums[left]; //we have only this current number in our answer
            
            while (right >= left) {
                //push right as much as possible
                while (right <  nums.size() - 1 && (((sum + nums[right + 1]) * (right - left + 2)) < k)) {
                    ++right;
                    sum += nums[right];
                }
                
                //if right reach "len-1" or next element is that big that cant add to our solution
                //then using math to calc all possible sub array in this range
                if (right == nums.size() - 1 || nums[right+1] >= k) {
                    
                    //if right reach "len-1" then this will set left to "len" ==> and mian loop will break at ==> if (left == nums.size())
                    //if right is not "len-1" then left will be set to that big number index which cant be include in our solution, and it will go
                    //  forward untill it find another starting point or reach to end of array
                    
                    max += ((long long)(right - left + 1) * (right - left + 2))/2;
                    left = right + 1;
                    break;
                }
                
                //if next number after right index is not that big and can be get include in our final answer
                //but its not that small to get include with our current left index then
                //we will add all possible subarrays for only "left" index, and push left forward
                //so at begging of loop right will try to push forward and add that number aswell
                max += right - left + 1;
                
                //left index value should no more be included in our final anwer
                sum -= nums[left];
                
                //push left forward
                ++left;
            }
        }
        return max;
    }
};
