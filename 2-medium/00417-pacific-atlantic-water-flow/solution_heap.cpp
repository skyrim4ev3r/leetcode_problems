/*
    using two min_heap, one for atlantic ocean, one for pacific ocean
    using two is_visited, one for atlantic ocean, one for pacific ocean

    using a grid with defalut valu of 0 and size of m*n

    incremnet every cells in grid that are reachable from """atlantic ocean""" by """1"""
    incremnet every cells in grid that are reachable from """pacific ocean""" by """1"""

    at final every cells in grid with value of """2""" are reachable from both side, and we can add all of them to """result"""
*/

class Solution {
    struct Cell {
        int height;
        int i;
        int j;
        bool operator<(const Cell& other) const {
            return height > other.height; // Reverse for min-heap
        }
    };

    inline void solve(vector<vector<int>>& heights, vector<vector<int>> &grid, priority_queue<Cell> &pq, vector<vector<bool>> &is_visited) {
        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<int>> directions{{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

         while (!pq.empty()) {

            Cell cell = pq.top();
            pq.pop();

            for (auto &dir: directions) {
                int new_i = cell.i + dir[0];
                int new_j = cell.j + dir[1];

                if (new_i >= rows || new_i < 0 || new_j >= cols || new_j < 0) {
                    continue;
                }

                if (is_visited[new_i][new_j]) {
                    continue;
                }

                is_visited[new_i][new_j] = true;

                int new_height = heights[new_i][new_j];

                if (new_height < cell.height) {
                    continue;
                }

                grid[new_i][new_j] += 1;
                pq.push(Cell {new_height, new_i, new_j});
            }

        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        priority_queue<Cell> atlantic_pq{};
        priority_queue<Cell> pacific_pq{};

        vector<vector<int>> grid = vector(rows, vector<int>(cols, 0));
        vector<vector<bool>> atlantic_is_visited = vector(rows, vector<bool>(cols, false));
        vector<vector<bool>> pacific_is_visited = vector(rows, vector<bool>(cols, false));


        for (int i{0}; i < rows; ++i) {
            for (int j{0}; j < cols; ++j) {

                if (i == 0 || j == 0) {
                    pacific_pq.push(Cell {heights[i][j], i, j});
                    pacific_is_visited[i][j] = true;
                    grid[i][j] += 1;
                }

                if (i == rows - 1 || j == cols - 1) {
                    atlantic_pq.push(Cell {heights[i][j], i, j});
                    atlantic_is_visited[i][j] = true;
                    grid[i][j] += 1;
                }
            }
        }

        solve(heights, grid, atlantic_pq, atlantic_is_visited);
        solve(heights, grid, pacific_pq, pacific_is_visited);

        vector<vector<int>> res{};

        for (int i{0}; i < rows; ++i) {
            for (int j{0}; j < cols; ++j) {
                if (grid[i][j] == 2) {
                    res.push_back(vector<int>{i, j});
                }
            }
        }

        return res;
    }
};
