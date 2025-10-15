class Solution:
    def checkDivisibility(self, n: int) -> bool:
        x, d_sum, d_mul = n, 0, 1
        while x > 0 :
            tmp = x % 10
            d_sum += tmp
            d_mul *= tmp
            x //= 10
        return n % (d_sum + d_mul) == 0