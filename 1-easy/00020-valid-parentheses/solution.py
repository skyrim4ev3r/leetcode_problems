class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        for ch in s:
            match ch:
                case '}' | ']' | ')':
                    if len(stack) == 0:
                        return False

                    top_char = stack[-1]

                    if (ch == '}' and top_char == '{') \
                        or (ch == ']' and top_char == '[') \
                        or (ch == ')' and top_char == '('):
                        stack.pop()
                    else:
                        return False

                case _:
                    stack.append(ch)

        return len(stack) == 0
