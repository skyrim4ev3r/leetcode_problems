class Solution:
    def findSmallestInteger(self, nums: List[int], value: int) -> int:
        
        remainders = [0] * value

        for num in nums:
            index = abs(num) % value

            # Adjust index for negative numbers
            if index != 0 and num < 0:
                index = value - index

            remainders[index] += 1

        res = 0
        while True:
            index = res % value

            if remainders[index] == 0:
                break

            remainders[index] -= 1

            res += 1

        return res
