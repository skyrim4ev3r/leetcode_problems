class Solution:
    def is_prime(self, num):
        if num <= 1:
            return False

        if num == 2 or num == 3 or num == 5:
            return True

        if num % 2 == 0 or num % 3 == 0 or num % 5 == 0:
            return False

        sq = int(sqrt(num))
        for i in range(7, sq + 1, 2):
            if num % i == 0:
                return False

        return True

    def diagonalPrime(self, nums: List[List[int]]) -> int:
        n = len(nums)
        max_num = 0
        for i in range(n):

            if max_num < nums[i][i] and self.is_prime(nums[i][i]):
                max_num = nums[i][i]

            if max_num < nums[i][n - 1 - i] and self.is_prime(nums[i][n - 1 - i]):
                max_num = nums[i][n - 1 - i]

        return max_num
