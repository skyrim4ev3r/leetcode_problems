class Solution:
    def sumFourDivisors(self, nums: List[int]) -> int:

        res = 0
        
        for num in nums :

            sq = int(sqrt(num))

            # if this condition be true then number of divisors are odd and cant be 4
            if sq*sq == num:
                continue

            # 1 and num are two divisors of num
            # so we start from count=2 and sum =1+num
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
