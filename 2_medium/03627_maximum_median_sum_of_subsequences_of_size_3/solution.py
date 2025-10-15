class Solution:
    def maximumMedianSum(self, nums: List[int]) -> int:
       return sum(sorted(nums)[len(nums)//3::2])
