class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        total_sum, total_max = 0, nums[0]
        for i in range(len(nums)):
            total_sum += nums[i]
            if total_sum > total_max:
                total_max = total_sum
            if total_sum < 0:
                total_sum = 0
        return total_max
