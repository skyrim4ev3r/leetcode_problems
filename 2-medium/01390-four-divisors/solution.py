class Solution:
    def sumFourDivisors(self, nums: List[int]) -> int:
        res = 0
        for num in nums :
            sq = int(sqrt(num))
            if sq*sq == num:
                continue
            count = 2
            t_sum = 1 + num
            for i in range(2,sq+1) :
                if num % i == 0 :
                    t_sum += i + num // i
                    count += 2
                if count > 4 :
                    break
            if count == 4 :
                res += t_sum
        return res
