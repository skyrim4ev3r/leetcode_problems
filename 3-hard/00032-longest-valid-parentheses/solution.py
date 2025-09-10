class Solution:
    def update_valid_positions(self, s, valid_positions):
        stack = []
        for i in range(len(s)):
            if len(stack) > 0:
                top_element = stack[-1]
                if (s[i] == '}' and top_element[1] == '{') \
                        or (s[i] == ']' and top_element[1] == '[') \
                        or (s[i] == ')' and top_element[1] == '('):
                    valid_positions[top_element[0]] = True
                    valid_positions[i] = True
                    stack.pop()
                    continue
            stack.append([i, s[i]])

    def max_continuous_substr_of_true(self, valid_positions):
        max_continuous_true, curr = 0, 0
        for pos in valid_positions:
            if pos:
                curr += 1
            else:
                curr = 0
            if curr > max_continuous_true:
                max_continuous_true = curr
        return max_continuous_true

    def longestValidParentheses(self, s: str) -> int:
        valid_positions = [False for _ in s];
        self.update_valid_positions(s, valid_positions)
        return self.max_continuous_substr_of_true(valid_positions)
