class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int target_rows, int target_cols) {
        int original_rows = mat.size();
        int original_cols = mat[0].size();

        if ((original_rows * original_cols != target_rows * target_cols)
            || (original_rows == target_rows && original_cols == target_cols))
        {
            return mat;
        }

        vector<vector<int>> res = vector<vector<int>>(target_rows, vector<int>(target_cols, 0));

        vector<int> tmp{};

        for (int i{target_rows - 1}; i >= 0; --i) {
            for (int j{target_cols - 1}; j >= 0; --j) {

                if (tmp.empty()) {
                    tmp = mat.back();
                    mat.pop_back();
                }

                res[i][j] = tmp.back();
                tmp.pop_back();
            }
        }

        return res;
    }
};
