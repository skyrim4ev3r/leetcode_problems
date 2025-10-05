class Solution:
    def decimalRepresentation(self, n: int) -> List[int]:
        multiplier = 1
        res = []
        while n > 0:
            tmp = (n % 10) * multiplier;
            if tmp != 0:
                res.append(tmp)
            multiplier *= 10
            n //= 10

        res.reverse()

        return res
