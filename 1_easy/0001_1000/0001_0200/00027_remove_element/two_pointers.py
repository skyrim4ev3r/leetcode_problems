class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:

        num_len = len(nums)
        k = 0

        for i in range(num_len):
            if nums[i] != val:
                nums[k] = nums[i]
                k += 1

        return k
