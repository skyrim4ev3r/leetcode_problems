class Solution:
    def getNoZeroIntegers(self, n: int) -> List[int]:
        for i in range(1,n):
            nums = [i, n-i]
            is_valid = True
            for a in nums:
                if not is_valid:
                    break
                while a > 0:
                    if a % 10 == 0:
                        is_valid = False
                        break
                    a //= 10
            if is_valid:
                return [i, n-i]
        return []
