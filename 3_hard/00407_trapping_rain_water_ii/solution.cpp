class Solution {
    struct Cell {
        int height, i, j;
        bool operator<(const Cell& other) const {
            return height > other.height;
        }
    };

public:
    int trapRainWater(vector<vector<int>>& height_map) {
        int m = height_map.size();
        int n = height_map[0].size();

        priority_queue<Cell> heap;
        vector<vector<bool>> is_visited(m, vector<bool>(n, false));

        for (int i{0}; i < m; ++i) {
            for (int j{0}; j < n; ++j) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    is_visited[i][j] = true;
                    heap.push(Cell{height_map[i][j], i, j});
                }
            }
        }

        int sum = 0;
        vector<vector<int>> directions = {{-1, 0}, {0, -1}, {1,0}, {0,1}};

        while (!heap.empty()) {
            Cell cell = heap.top();
            heap.pop();

            int old_j = cell.j;
            int old_i = cell.i;
            int old_height = cell.height;

            for (auto &dir: directions) {
                int new_i = old_i + dir[0];
                int new_j = old_j + dir[1];

                if (new_i < 0 || new_i >= m || new_j < 0 || new_j >= n) {
                    continue;
                }

                if (is_visited[new_i][new_j]) {
                    continue;
                }

                int new_height = height_map[new_i][new_j];
                sum += std::max(0, old_height - new_height);
                is_visited[new_i][new_j] = true;
                heap.push(Cell{std::max(new_height, old_height), new_i, new_j});
            }
        }

        return sum;
    }
};
