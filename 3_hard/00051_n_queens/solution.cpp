/*
    we use n*n board of bools to represent chess board:
        true  => there is queen on that square
        false => square is free
*/
class Solution {
    vector<vector<bool>> board{};
    
    vector<vector<string>> res;
    string tmp_string{};
    int max;
    
    /*
        checking if adding queen to this square will hit previous added queens or not
    */
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
    
    /*
        when we finally place all of our queens on the board then we need to save current board
    */
    void add_board_state_to_res() {
        vector<string> v{};
        for (int y{0}; y < max; ++y) {
            for (int x{0}; x < max; ++x) {
                if (board[x][y]) {
                    /*
                      if board be 4x4 then
                            for row like: "false, true, false, false" we need convert it to ".Q.."
                            our tmp_string is filled by '.' so its "...."
                            so we change its 2nd element to 'Q' to get ".Q.."
                    */
                    tmp_string[x] = 'Q';  
                    
                    //we save tmp_string into vector
                    v.push_back(tmp_string);
                    
                    // we need to replace 'Q' with '.' after we insert tmp_string, because we need this string for entire program
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
        
        //creating a row of '.' character for reducing recreating string for reach answer
        tmp_string = string(max, '.'); 
        
        //initial n*n board with default false for each element
        board.resize(max, vector<bool>(max, false));
        
        //starting backtrack with row = 0
        solve_helper(0);
        return res;
    }
};
