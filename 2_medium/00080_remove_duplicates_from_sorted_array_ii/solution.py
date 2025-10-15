class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        nums_len = len(nums)

        if nums_len < 3:
            return nums_len

        curr_len = 2

        for i in range(2, nums_len):
            if nums[i] == nums[curr_len - 2]:
                continue

            nums[curr_len] = nums[i]
            curr_len += 1

        return curr_len
