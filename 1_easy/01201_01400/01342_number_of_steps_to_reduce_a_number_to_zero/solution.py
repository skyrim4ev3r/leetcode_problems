class Solution:
    def numberOfSteps(self, num: int) -> int:

        count = 0

        while num > 0:
            count += 1
            if (num & 1) == 1:
                num -= 1
            else:
                num //= 2

        return count
