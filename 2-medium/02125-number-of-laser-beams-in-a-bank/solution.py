class Solution:
    def numberOfBeams(self, bank: List[str]) -> int:
        stack = []
        for row in bank:
            count = 0
            for ch in row:
                if ch == '1':
                    count += 1

            if count > 0:
                stack.append(count)

        res = 0
        if stack:
            for i in range(len(stack) - 1, 0, -1):
                res += stack[i] * stack[i - 1]

        return res
