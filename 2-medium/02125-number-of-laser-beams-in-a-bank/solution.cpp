class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> stack{};
        for (auto &row: bank) {
            int count = 0;
            for (auto &ch: row) {
                if (ch == '1') {
                    count += 1;
                }
            }

            if (count > 0) {
                stack.push_back(count);
            }
        }

        int res = 0;
        if (!stack.empty()) {
            for (int i{(int) stack.size() -1}; i > 0; --i) {
                res += stack[i] * stack[i - 1];
            }
        }

        return res;
    }
};
