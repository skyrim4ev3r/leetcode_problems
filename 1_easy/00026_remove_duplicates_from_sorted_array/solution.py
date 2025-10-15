class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:

        nums_len = len(nums)
        index = 0

        for i in range(1, nums_len):
            if nums[i] != nums[i - 1]:
                index += 1
                nums[index] = nums[i]

        return index + 1
