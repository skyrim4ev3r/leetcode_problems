class Solution:
    def smallestIndex(self, nums: List[int]) -> int:
        for i in range(0,len(nums)):
            val, index = nums[i], i
            while val > 0 :
                index -= val%10
                val //=10
            if index == 0 : 
                return i
        return -1
