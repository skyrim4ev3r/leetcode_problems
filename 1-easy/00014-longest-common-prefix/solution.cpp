class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int strs_len = strs.size();
        int min_str_len = INT_MAX;
        string res{};

        for (auto s: strs) {
            min_str_len = min(min_str_len, (int) s.size());
        }

        for (int j{0}; j <  min_str_len; ++j) {
            for (int i{1}; i < strs_len; ++i) {
                if (strs[i][j] != strs[i - 1][j]) {
                    return res;
                }
            }

            res.push_back(strs[0][j]);
        }

        return res;
    }
};
