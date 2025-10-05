/*
    using two is_visited, one for atlantic ocean, one for pacific ocean

    dfs every cells that are reachable from """atlantic ocean"""
    dfs every cells that are reachable from """pacific ocean"""

    at final every cells in grid with is_visited = true in both is_visited are reachable from both side, and we can add all of them to """result"""
*/
class Solution {
    vector<vector<int>> directions{{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

    int rows;
    int cols;

    void dfs(vector<vector<int>>& heights, vector<vector<bool>> &is_visited, int i, int j) {

        is_visited[i][j] = true;

        for (auto &dir: directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            if (new_i >= rows || new_i < 0 || new_j >= cols || new_j < 0) {
                continue;
            }

            if (is_visited[new_i][new_j]) {
                continue;
            }

            if (heights[new_i][new_j] < heights[i][j]) {
                continue;
            }

            dfs(heights, is_visited, new_i, new_j);
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rows = heights.size();
        cols = heights[0].size();

        vector<vector<bool>> atlantic_is_visited = vector(rows, vector<bool>(cols, false));
        vector<vector<bool>> pacific_is_visited = vector(rows, vector<bool>(cols, false));


        for (int i{0}; i < rows; ++i) {
            for (int j{0}; j < cols; ++j) {

                if (i == 0 || j == 0) {
                    dfs(heights, pacific_is_visited, i, j);
                }

                if (i == rows - 1 || j == cols - 1) {
                    dfs(heights, atlantic_is_visited, i, j);
                }
            }
        }

        vector<vector<int>> res{};

        for (int i{0}; i < rows; ++i) {
            for (int j{0}; j < cols; ++j) {
                if (atlantic_is_visited[i][j] && pacific_is_visited[i][j]) {
                    res.push_back(vector<int>{i, j});
                }
            }
        }

        return res;
    }
};
