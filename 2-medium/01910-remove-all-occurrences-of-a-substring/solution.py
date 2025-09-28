class Solution:
    def remove_occurrences_helper(self, s, part):
        left = 0
        right = len(part) - 1
        while right < len(s):
            is_equal = True
            for i in range(len(part)):
                if s[left + i] != part[i]:
                    is_equal = False
                    break

            if is_equal:
                res = s[0:left]
                res += s[right+1:]
                s[:] = res
                return True
            right += 1
            left += 1

        return False

    def removeOccurrences(self, s: str, part: str) -> str:
        s = list(s)
        part = list(part)
        while self.remove_occurrences_helper(s, part):
            continue
        return "".join(s)
