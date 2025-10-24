class Solution {
public:
    string decodeString(string s) {

        string current_str{};
        int multiplier = 0;
        vector<int> stack_multipliers{};
        vector<string> stack_strs{};

        for (auto ch: s) {
            if (ch >= '0' && ch <= '9') {
                multiplier = multiplier * 10 + ch - '0';
            } else if (ch == '[') {
                stack_multipliers.push_back(multiplier);
                stack_strs.push_back(current_str);
                multiplier = 0;
                current_str = "";
            } else if (ch >= 'a' && ch <= 'z') {
                current_str.push_back(ch);
            } else {
                int last_multiplier = stack_multipliers[stack_multipliers.size() - 1];
                string last_str = stack_strs[stack_strs.size() - 1];
                string tmp{};
                for (int i{0}; i < last_multiplier; ++i) {
                        tmp += current_str;
                }
                current_str = last_str + tmp;
                stack_multipliers.pop_back();
                stack_strs.pop_back();
            }
        }

        return current_str;
    }
};
