class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int rows = strs.size();
        int cols = strs[0].size();
        int count = 0;

        for (int j{0}; j < cols; ++j) {

            bool is_sorted = true;
            for (int i{1}; i < rows; ++i) {
                if (strs[i][j] < strs[i - 1][j]) {
                    is_sorted = false;
                    break;
                }
            }

            if (!is_sorted) {
                count += 1;
            }
        }

        return count;
    }
};
