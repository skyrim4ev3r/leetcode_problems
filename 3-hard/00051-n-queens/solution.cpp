class Solution {
    vector<vector<bool>> board{};
    vector<vector<string>> res;
    string tmp_string{};
    int max;
    bool is_safe(int x, int y) {
        for (int ofs{0}; ofs < max; ++ofs) {
            if (x >= ofs && y >= ofs && board[x - ofs][y - ofs]) {
                return false;
            }
            if (x + ofs < max && y >= ofs && board[x + ofs][y - ofs]) {
                return false;
            }
            if (y >= ofs && board[x][y - ofs]) {
                return false;
            }
        }
        return true;
    }
    void add_board_state_to_res() {
        vector<string> v{};
        for (int y{0}; y < max; ++y) {
            for (int x{0}; x < max; ++x) {
                if (board[x][y]) {                         
                    tmp_string[x] = 'Q';                                
                    v.push_back(tmp_string);
                    tmp_string[x] = '.';
                    break;
                }
            }
        }
        res.push_back(v);                   
    }
    void solve_helper(int currentrow) {
        for (int x{0}; x < max; ++x) {
            if (is_safe(x, currentrow)) {
                board[x][currentrow] = true;
                if (currentrow == max-1) {
                    add_board_state_to_res();
                } else {
                    solve_helper(currentrow + 1);
                }
                board[x][currentrow] = false;
            }
        }      
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        max = n;
        tmp_string = string(max, '.');
        board.resize(max, vector<bool>(max, false));
        solve_helper(0);
        return res;
    }
};
