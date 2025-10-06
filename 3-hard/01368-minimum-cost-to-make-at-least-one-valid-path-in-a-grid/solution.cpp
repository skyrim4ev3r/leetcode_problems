class Solution {
    struct Cell {
        int cost;
        int i;
        int j;

        bool operator<(const Cell& other) const {
            return cost > other.cost; // Reverse for min-heap
        }

        bool operator==(const Cell& other) const {
            return (i == other.i) && (j == other.j);
        }
    };
public:
    int minCost(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int directions_len = directions.size();
        vector<vector<int>> cost_matrix = vector<vector<int>>(rows, vector<int>(cols, INT_MAX));
        priority_queue<Cell> heap{};

        heap.push(Cell {0, 0, 0});
        cost_matrix[0][0] = 0;

        while (!heap.empty()) {
            Cell cell = heap.top();
            heap.pop();

            if (cell.i == rows - 1 && cell.j == cols - 1) {
                return cell.cost;
            }

            for (int index{0}; index < directions_len; ++index) {
                int new_i = cell.i + directions[index][0];
                int new_j = cell.j + directions[index][1];

                if (new_i >= rows || new_j >= cols || new_i < 0 || new_j < 0) {
                    continue;
                }

                int new_cost = 0;

                if (index == (grid[cell.i][cell.j] - 1)) {
                    new_cost = cell.cost;
                } else {
                    new_cost = cell.cost + 1;
                }

                if (new_cost < cost_matrix[new_i][new_j]) {
                    cost_matrix[new_i][new_j] = new_cost;
                    heap.push(Cell { new_cost, new_i, new_j });
                }

            }
        }

        return -1;
    }
};
