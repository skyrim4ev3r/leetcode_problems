class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        // Check all rows are valid
        for (int i{0}; i < 9; ++i) {
            bool is_seen[9]{};
            for (int j{0}; j < 9; ++j) {
                if (board[i][j] != '.') {
                    int is_seen_index = board[i][j] - '1';
                    if (is_seen[is_seen_index]) {
                        return false;
                    }
                    is_seen[is_seen_index] = true;
                }
            }
        }

        // Check all cols are valid
        for (int j{0}; j < 9; ++j) {
            bool is_seen[9]{};
            for (int i{0}; i < 9; ++i) {
                if (board[i][j] != '.') {
                    int is_seen_index = board[i][j] - '1';
                    if (is_seen[is_seen_index]) {
                        return false;
                    }
                    is_seen[is_seen_index] = true;
                }
            }
        }

       // Check all 3*3 sub-boxes
        for (int cell{0}; cell < 9; ++cell) {
            bool is_seen[9]{};
            int start_i = (cell / 3) * 3;
            int start_j = (cell % 3) * 3;
            for (int i{start_i}; i < start_i + 3; ++i) {
                for (int j{start_j}; j < start_j + 3; ++j) {
                    if (board[i][j] != '.') {
                        int is_seen_index = board[i][j] - '1';
                        if (is_seen[is_seen_index]) {
                            return false;
                        }
                        is_seen[is_seen_index] = true;
                    }
                }
            }
        }

        return true;
    }
};
