class Solution {

    vector<vector<int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int target_path_len{0};
    int count{0};
    int rows{0};
    int cols{0};

    void dfs(vector<vector<int>> &grid, int curr_path_len, int i, int j) {
        if (grid[i][j] == -1) {
            return;
        }

        if (grid[i][j] == 2) {
            if (target_path_len == curr_path_len) {
                count += 1;
            }

            return;
        }

        grid[i][j] = -1;
        for (auto &direction: directions) {

            int new_i = i + direction[0];
            int new_j = j + direction[1];

            if (new_i < 0 || new_j < 0 || new_i >= rows || new_j >= cols) {
                continue;
            }

            dfs(grid, curr_path_len + 1, new_i, new_j);
        }
        grid[i][j] = 0;
    }

public:
    int uniquePathsIII(vector<vector<int>>& grid) {

        rows = grid.size();
        cols = grid[0].size();
        int  i_start{0}, j_start{0};

        for (int i{0}; i < rows; ++i) {
            for (int j{0}; j < cols; ++j) {
                if (grid[i][j] == 0 || grid[i][j] == 2) {
                    target_path_len += 1;
                }

                if (grid[i][j] == 1) {
                    i_start = i;
                    j_start = j;
                }
            }
        }

        dfs(grid, 0, i_start, j_start);

        return count;
    }
};
