class Solution {
public:
    string removeOuterParentheses(string s) {
        string res{};
        int left_index = 0;
        int open_count = 0;
        int close_count = 0;
        int s_len = s.size();

        for (int i{0}; i < s_len; ++i) {
            if (s[i] == '(') {
                open_count += 1;
            } else {
                close_count += 1;
            }

            if (open_count == close_count) {
                int size = i - left_index - 1;
                res += s.substr(left_index + 1, size);
                left_index = i + 1;
                open_count = 0;
                close_count = 0;
            }
        }

        return res;
    }
};
