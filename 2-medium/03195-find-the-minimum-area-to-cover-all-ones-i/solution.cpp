class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int max_i = 0;
        int min_i = grid.size();
        int max_j = 0;
        int min_j = grid[0].size();

        for (int i{0}; i < grid.size(); ++i) {
            for (int j{0}; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    max_i = i; // Directly assign since var "i" is always growing
                    if (i < min_i) {
                        min_i = i;
                    }
                    max_j = max(max_j, j);
                    min_j = min(min_j, j);
                }
            }
        }

        if (max_i < min_i) {
            return 0;
        }

        return (max_i - min_i + 1) * (max_j - min_j + 1);
    }
};
