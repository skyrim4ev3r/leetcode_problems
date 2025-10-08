class Solution:
    def addBinary(self, a: str, b: str) -> str:

        a = list(a)
        b = list(b)

        offset = 0
        ord_0 = ord('0')

        if len(a) < len(b):
            a, b = b, a

        for i in range(len(a) - 1, -1, -1):

            b_char = '0'

            if b:
                b_char = b.pop()

            byte_sum = (ord(a[i]) - ord_0) + (ord(b_char) - ord_0) + offset
            offset = 0
            if byte_sum > 1:
                byte_sum -= 2
                offset = 1

            a[i] = chr(byte_sum + ord_0)

            if offset == 0 and not b:
                break

        if offset == 1:
            a.insert(0, '1')

        return "".join(a)
