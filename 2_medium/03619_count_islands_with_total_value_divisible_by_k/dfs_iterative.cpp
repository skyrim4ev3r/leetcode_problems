class Solution {
    long dfs_iterative(vector<vector<int>> &grid, size_t i, size_t j, size_t rows, size_t cols) {

        long sum = grid[i][j];

        grid[i][j] = 0;

        stack<pair<size_t, size_t>> stack;
        stack.push(pair(i, j));

        while (!stack.empty()) {
            auto tmp = stack.top();
            size_t x = tmp.first;
            size_t y = tmp.second;
            stack.pop();

            if (x > 0 && grid[x - 1][y] != 0) {
                sum += grid[x - 1][y];
                grid[x - 1][y] = 0;
                stack.push(pair(x - 1, y));
            }

            if (x < rows - 1 && grid[x + 1][y] != 0) {
                sum += grid[x + 1][y];
                grid[x + 1][y] = 0;
                stack.push(pair(x + 1, y));
            }

            if (y > 0 && grid[x][y - 1] != 0) {
                sum += grid[x][y - 1];
                grid[x][y - 1] = 0;
                stack.push(pair(x, y - 1));
            }

            if (y < cols - 1 && grid[x][y + 1] != 0) {
                sum += grid[x][y + 1];
                grid[x][y + 1] = 0;
                stack.push(pair(x, y + 1));
            }
        }

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

                    long sum = dfs_iterative(grid, i, j, rows, cols);

                    if (sum % k == 0) {
                        count += 1;
                    }
                }
            }
        }

        return count;
    }
};
