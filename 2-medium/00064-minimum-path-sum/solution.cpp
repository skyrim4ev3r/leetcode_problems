class Solution {
    struct Cell {
        int val;
        int i;
        int j;
        bool operator<(const Cell& other) const {
            return val > other.val; // Reverse for min-heap
        }
    };

public:
    int minPathSum(vector<vector<int>>& grid) {
        priority_queue<Cell> min_heap;
        const int rows = grid.size();
        const int cols = grid[0].size();

        if (rows == 1 && cols == 1) {
            return grid[0][0];
        }

        vector<vector<bool>> is_visited(rows, vector<bool>(cols, false));

        min_heap.push(Cell {grid[0][0], 0, 0});
        is_visited[0][0] = true;
        vector<vector<int>> directions{{0,1}, {1,0}};
        while (!min_heap.empty()) {
            Cell cell = min_heap.top();
            min_heap.pop();
            for (auto &dir: directions) {
                int new_i = cell.i + dir[0];
                int new_j = cell.j + dir[1];

                if (new_j >= cols || new_i >= rows || is_visited[new_i][new_j]) {
                    continue;
                }

                is_visited[new_i][new_j] = true;
                int new_val = grid[new_i][new_j] + cell.val;

                if (new_i == rows - 1 && new_j == cols - 1) {
                    return new_val;
                }

                min_heap.push(Cell {new_val, new_i, new_j});
            }
        }

        return -1;
    }
};
