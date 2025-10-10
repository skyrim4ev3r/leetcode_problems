class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box_grid) {
        int original_rows = box_grid.size();
        int original_cols = box_grid[0].size();

        int rows = original_cols;
        int cols = original_rows;

        vector<vector<char>> res(rows, vector<char>(cols, '.'));
        for (int i{0}; i < rows; ++i) {
            for (int j{0}; j < cols; ++j) {
                res[i][j] = box_grid[cols - j - 1][i];
            }
        }

        for (int j{0}; j < cols; ++j) {

            int top = 0;
            int bottom = 0;

            while (bottom < rows) {

                int leaf_count = 0;
                while (bottom < rows && res[bottom][j] != '*') {
                    if (res[bottom][j] == '#') {
                        leaf_count += 1;
                        res[bottom][j] = '.';
                    }
                    bottom += 1;
                }

                for (int i{bottom - leaf_count}; i < bottom; ++i) {
                    res[i][j] = '#';
                }

                bottom = bottom + 1;
                top = bottom;
            }
        }

        return res;
    }
};
