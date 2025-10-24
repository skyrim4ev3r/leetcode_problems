class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> rows_min_vals{};
        vector<int> cols_max_vals{};
        vector<int> res{};

        for (int j{0}; j < cols; ++j) {
            int max = INT_MIN;
            for (int i{0}; i < rows; ++i) {
                max = std::max(max, matrix[i][j]);
            }
            cols_max_vals.push_back(max);
        }

        for (int i{0}; i < rows; ++i) {
            int min = INT_MAX;
            for (int j{0}; j < cols; ++j) {
                min = std::min(min, matrix[i][j]);
            }
            rows_min_vals.push_back(min);
        }

        for (int i{0}; i < rows; ++i) {
            for (int j{0}; j < cols; ++j) {
                if (matrix[i][j] == rows_min_vals[i] && matrix[i][j] == cols_max_vals[j]) {
                    res.push_back(matrix[i][j]);
                }
            }
        }

        return res;
    }
};
