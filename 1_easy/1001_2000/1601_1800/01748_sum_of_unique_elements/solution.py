class Solution:
    def sumOfUnique(self, nums: List[int]) -> int:
        return sum(key for key, value in Counter(nums).items() if value == 1)
