class Solution:
    def minOperations(self, nums: List[int]) -> int:
        count = 0
        for i in range(1, len(nums)):
            if nums[i - 1] >= nums[i]:
                amount_to_add = nums[i - 1] - nums[i] + 1
                count += amount_to_add
                nums[i] += amount_to_add

        return count
