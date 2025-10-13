class Solution {
     void dfs(vector<vector<char>> &grid, vector<vector<int>> &directions, int i, int j) {

        if (grid[i][j] == '0') {
            return;
        }

        grid[i][j] = '0';

        for (auto &dir: directions) {

            int new_i = i + dir[0];
            int new_j = j + dir[1];

            if (new_i < 0 || new_j < 0 || new_i >= grid.size() || new_j >= grid[0].size()) {
                continue;
            }

            dfs(grid, directions, new_i, new_j);
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int count = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        for (int i{0}; i < rows; ++i) {
            for (int j{0}; j < cols; ++j) {
                if (grid[i][j] == '1') {
                    count += 1;
                    dfs(grid, directions, i, j);
                }
            }
        }

        return count;
    }
};
