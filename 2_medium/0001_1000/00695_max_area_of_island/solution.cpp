class Solution {
    int count;
    void backtrack(vector<vector<int>>& grid, int i, int j) {
        if (grid[i][j] == 0) {
            return;
        }

        count += 1;
        grid[i][j] = 0;

        if (i > 0) {
            backtrack(grid, i - 1, j);
        }
        if (i < grid.size() - 1) {
            backtrack(grid, i + 1, j);
        }

        if (j > 0) {
            backtrack(grid, i, j - 1);
        }
        if (j < grid[i].size() - 1) {
            backtrack(grid, i, j + 1);
        }
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max = 0;
        for (int i{0}; i < grid.size(); ++i) {
            for (int j{0}; j < grid[i].size(); ++j) {
                if (grid[i][j] == 1) {
                    count = 0;
                    backtrack(grid, i, j);
                    max = std::max(max, count);
                }
            }
        }

        return max;
    }
};
