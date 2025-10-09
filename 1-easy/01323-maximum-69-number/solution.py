class Solution:
    def maximum69Number (self, num: int) -> int:
        digits = []

        while num > 0:
            digits.append(num % 10)
            num //= 10

        res = 0
        can_change = True

        while digits:
            digit = digits.pop()
            res *= 10
            if can_change and digit == 6:
                can_change = False
                res += 9
            else:
                res += digit

        return res
