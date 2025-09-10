class Solution {
    void reformat_string(string &s) {
        stack<pair<int, char>> stack;
        for (auto i{0}; i < s.size(); ++i){
            if(stack.size() > 0) {
                auto top_element{stack.top()};
                if ((s[i] == '}' && top_element.second == '{')
                    || (s[i] == ']' && top_element.second == '[')
                    || (s[i] == ')' && top_element.second == '('))
                {
                    s[top_element.first] = '+';
                    s[i] = '+';
                    stack.pop();
                    continue;
                }
            }
            stack.push(pair<int, char>(i, s[i]));
        }
    }
    int max_continuous_substr_of_char_plus(string &s){
        int max{0}, curr{0};
        for (auto i{0};i < s.size();i++) {
            if (s[i] == '+') {
                ++curr;
            } else {
                curr = 0;
            }
            if (curr > max) {
                max = curr;
            }
        }
        return max;
    }
public:
    int longestValidParentheses(string s) {
        reformat_string(s);
        return max_continuous_substr_of_char_plus(s);
    }
};
