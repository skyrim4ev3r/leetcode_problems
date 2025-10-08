class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        offset = 1
        digits_len = len(digits)

        for i in range(digits_len - 1, -1, -1):
            digits[i] += offset
            offset = 0
            if digits[i] > 9:
                digits[i] -= 10
                offset = 1
            else:
                break

        if offset == 1:
            digits.append(0)
            digits[0] = 1

        return digits
