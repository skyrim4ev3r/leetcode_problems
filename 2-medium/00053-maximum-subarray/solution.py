class Solution:
    def maxSubArray(self, nums: List[int]) -> int:

        total_sum, total_max = 0, nums[0]
        
        for i in range(len(nums)):

            total_sum += nums[i]

            if total_sum > total_max:
                total_max = total_sum

            #because of this: then starting point can never be negative, so if 
            #sum of some "positive_start_point" up to "some negative_ending_point" be negative then
            #none of subarrays of that subaray cant be positive when they ""include"" ==> "negative_ending_point"
            #because even with help of our positive_starting point it cant get positive
            #so we can start to sum elements again!
            if total_sum < 0:
                total_sum = 0

        return total_max
