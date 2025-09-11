/*
    we use n*n board of bools to represent chess board:
        true  => there is queen on that square
        false => square is free
*/
impl Solution {
    /*
        checking if adding queen to this square will hit previous added queens or not
    */
    fn is_safe(x: usize, y: usize, max: usize, board: &mut Vec<Vec<bool>>) -> bool {
        for ofs in 0..max {
            if x  >= ofs && y >= ofs && board[x-ofs][y-ofs] {
                return false;
            }
            if x + ofs < max && y >= ofs && board[x + ofs][y - ofs] {
                return false;
            }
            if y >= ofs && board[x][y - ofs] {
                return false;
            }
        }
        return true;
    }
    
    /*
        when we finally place all of our queens on the board then we need to save current board
    */
    fn add_board_state_into_res(max: usize, board: &mut Vec<Vec<bool>>, res: &mut Vec<Vec<String>>) {
        let mut v: Vec<String> = Vec::new();
        for y in 0..max {
            //vector will take ownership of this string, so recreating string is efficent
            //  though still using Vec<u8> can add slighty performance, but its not that important in this problem 
            let mut tmp: String = String::new();
            for x in 0..max {
                if(board[x][y]) {                         
                    tmp.push('Q');
                } else {
                    tmp.push('.');
                }
            }
            v.push(tmp);
        }
        res.push(v);                   
    }
    
    fn solve_helper(current_row: usize, max: usize,  board: &mut Vec<Vec<bool>>, res: &mut Vec<Vec<String>>) {
        for x in 0..max {
            if Self::is_safe(x, current_row, max, board) {
                board[x][current_row] = true;
                if current_row == max-1 {
                    Self::add_board_state_into_res(max, board, res);
                } else {
                    Self::solve_helper(current_row + 1, max, board, res);
                }
                board[x][current_row] = false;
            }
        }      
    }
    
    pub fn solve_n_queens(n: i32) -> Vec<Vec<String>> {
    
        //initial n*n board with default false for each element
        let mut board = vec![vec![false;n as usize];n as usize];
        
        let mut res: Vec<Vec<String>> = Vec::new();
        
        //starting backtrack with row = 0
        Self::solve_helper(0usize, n as usize, &mut board, &mut res);
        res
    }
}
