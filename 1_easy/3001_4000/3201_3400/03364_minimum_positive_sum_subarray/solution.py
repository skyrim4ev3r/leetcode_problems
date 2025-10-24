class Solution:
    def minimumSumSubarray(self, nums: List[int], l: int, r: int) -> int:
        min_positive_sum = -1
        n = len(nums)
        l -= 1
        r -= 1

        for i in range(n-l):
            curr_sum = 0
            for j in range(i, min(i + r, n - 1) + 1):
                curr_sum += nums[j]
                if j >= i + l and curr_sum > 0 and (curr_sum < min_positive_sum or min_positive_sum == -1):
                    min_positive_sum = curr_sum

        return min_positive_sum
