class Solution:
    def sortArrayByParityII(self, nums: List[int]) -> List[int]:

        odd = 1
        even = 0
        nums_len = len(nums)

        while even < nums_len and odd < nums_len:
            if (nums[odd] & 1) != 1 or (nums[even] & 1) != 0:
                while (nums[odd] & 1) == 1:
                    odd += 2
                while (nums[even] & 1) == 0:
                    even += 2

                tmp = nums[even]
                nums[even] = nums[odd]
                nums[odd] = tmp

            even += 2
            odd += 2

        return nums
