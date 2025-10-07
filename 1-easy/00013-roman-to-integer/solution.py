class Solution:
    def romanToInt(self, s: str) -> int:
        total_sum = 0
        curr_max = 0

        for i in range(len(s) - 1, -1, -1):

            curr_num = 0

            match s[i]:
                case 'I':
                    curr_num = 1
                case 'V':
                    curr_num = 5
                case 'X':
                    curr_num = 10
                case 'L':
                    curr_num = 50
                case 'C':
                    curr_num = 100
                case 'D':
                    curr_num = 500
                case 'M':
                    curr_num = 1000

            if curr_num >= curr_max:
                total_sum += curr_num
                curr_max = curr_num
            else:
                total_sum -= curr_num

        return total_sum
