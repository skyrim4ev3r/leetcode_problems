class Solution:
    def findDuplicate(self, nums: List[int]) -> int:

        num = 0
        for i in range(len(nums)):
            num = abs(nums[i])
            if nums[num] > 0:
                nums[num] *= -1
            else:
                break

        for i in range(len(nums)):
            if nums[i] < 0:
                nums[i] *= -1

        return num
