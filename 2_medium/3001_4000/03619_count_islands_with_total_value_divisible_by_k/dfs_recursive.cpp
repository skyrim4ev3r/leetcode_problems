class Solution {
    long dfs_recursive(vector<vector<int>> &grid, size_t i, size_t j, size_t rows, size_t cols) {

        if (i >= rows || j >= cols || grid[i][j] == 0) {
            return 0;
        }

        long sum = grid[i][j];
        grid[i][j] = 0;

        sum += dfs_recursive(grid, i - 1, j, rows, cols);
        sum += dfs_recursive(grid, i + 1, j, rows, cols);
        sum += dfs_recursive(grid, i, j - 1, rows, cols);
        sum += dfs_recursive(grid, i, j + 1, rows, cols);

        return sum;
    }

public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int count = 0;
        size_t rows = grid.size();
        size_t cols = grid[0].size();

        for (size_t i{0}; i < rows; ++i) {
            for (size_t j{0}; j < cols; ++j) {
                if (grid[i][j] != 0) {
                    long sum = dfs_recursive(grid, i, j, rows, cols);

                    if (sum % k == 0) {
                        count += 1;
                    }
                }
            }
        }

        return count;
    }
};
