/*
    its same as another ==> hard problem ==> 00051
    look comments on that solutions, because this is just a lighter version of that problem
*/

class Solution {
    vector<vector<bool>> board{};
    int count{0};
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
    
    void solve_helper(int currentrow) {
        for (int x{0}; x < max; ++x) {
            if (is_safe(x, currentrow)) {
                board[x][currentrow] = true;
                if (currentrow == max-1) {
                    ++count;
                } else {
                    solve_helper(currentrow + 1);
                }
                board[x][currentrow] = false;
            }
        }
    }
    
public:
    int totalNQueens(int n) {
        // Uncomment the following lines to use the lookup table for n = 1 to 9 to gain execution speed
        /* if (1 <= n && n <= 9) {
            return (int []){1, 0, 0, 2, 10, 4, 40, 92, 352}[n - 1];
        } */

        // Backtracking solutin
        max = n;
        board.resize(max, vector<bool>(max, false));
        solve_helper(0);
        return count;
    }
};
