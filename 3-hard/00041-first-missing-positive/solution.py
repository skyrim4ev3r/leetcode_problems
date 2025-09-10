class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        n = len(nums)
        # at worst case if vector of len n contains 1..n then we need n+1 space
        # that extra space is pos[0] and it will get ignore to easily map valid nums to thier index
        pos = [False for _ in range(n+1)]
        for num in nums:
            # we can ignore numers greather than n, because if ther be any then at least some int between 1..n is missed
            if num > 0 and num <= n:
                pos[num] = True
        # start from 1, ignoring pos[0]
        for i in range(1,n+1):
            if pos[i] == False:
                return i
        return n + 1 #this happens at worst case when vector of len n have 1..n values
