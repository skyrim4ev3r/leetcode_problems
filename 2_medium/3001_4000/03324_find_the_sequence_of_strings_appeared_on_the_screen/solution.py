class Solution:
    def stringSequence(self, target: str) -> List[str]:
        target_chars = list(target)
        screen = []
        res = []
        index = 0
        while screen != target_chars:
            if len(screen) == 0 or screen[index] == target_chars[index]:
                screen.append('a')
                index = len(screen) - 1
            else:
                screen[index] = chr(ord(screen[index]) + 1)

            res.append("".join(screen))

        return res
