class Solution:
    def smallestPalindrome(self, s: str) -> str:
        s = list(s)
        SIZE = 26
        freq = [0] * 26

        for ch in s:
            freq[ord(ch) - ord('a')] += 1

        l = 0
        r = len(s) - 1

        for i in range(SIZE):
            if (freq[i] & 1) == 1:
                mid = len(s) // 2
                s[mid] = chr(i + ord('a'))

            for j in range(freq[i] // 2):
                s[l] = chr(i + ord('a'))
                s[r] = chr(i + ord('a'))
                l += 1
                r -= 1

        return "".join(s)
