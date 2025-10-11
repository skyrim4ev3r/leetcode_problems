class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<int> row_vals = vector<int>(m, 0);
        vector<int> col_vals = vector<int>(n, 0);

        for (auto &index: indices) {
            row_vals[index[0]] += 1;
            col_vals[index[1] ] += 1;
        }

        int count = 0;

        for (int row_val: row_vals) {
            for (int col_val: col_vals) {
                if (((row_val + col_val) & 1) == 1) {
                    count += 1;
                }
            }
        }

        return count;
    }
};
