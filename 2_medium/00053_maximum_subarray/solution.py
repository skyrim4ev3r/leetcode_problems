INT_MIN = -sys.maxsize - 1

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:

        total_sum = 0
        total_max = INT_MIN
        nums_len = len(nums)
        
        for i in range(nums_len):
            total_sum += nums[i]

            if total_sum > total_max:
                total_max = total_sum
            
            # If sum be less than 0, then reset sum to 0 and start again
            if total_sum < 0:
                total_sum = 0

        return total_max
