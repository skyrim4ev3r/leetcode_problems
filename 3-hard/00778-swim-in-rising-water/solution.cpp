class Solution {
    struct Cell {
        int cost;
        int steps;
        int i;
        int j;
        bool operator<(const Cell& other) const {
            return cost > other.cost; // Reverse for min-heap
        }
    };
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        if (n <= 1) {
            return 0;
        }

        vector<vector<bool>> is_visited =  vector<vector<bool>>(n, vector<bool>(n, false));

        vector<vector<int>> directions {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        priority_queue<Cell> heap{};

        heap.push(Cell{grid[0][0], 0, 0, 0});
        is_visited[0][0] = true;

        while (!heap.empty()) {
            Cell cell = heap.top();
            heap.pop();

            for (auto &dir: directions) {
                int new_i = cell.i + dir[0];
                int new_j = cell.j + dir[1];

                if (new_i < 0 || new_i >= n || new_j < 0 || new_j >= n) {
                    continue;
                }

                if (is_visited[new_i][new_j]) {
                    continue;
                }

                is_visited[new_i][new_j] = true;

                int new_cost = std::max(grid[new_i][new_j], cell.cost);
                int new_steps = cell.steps + 1;

                if (new_i == n - 1 && new_j == n - 1) {
                    return std::max(new_cost, new_steps);
                }

                heap.push(Cell{new_cost, new_steps, new_i, new_j});

            }
        }

        return -1;
    }
};
