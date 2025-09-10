impl Solution {
    fn is_safe(x :usize, y: usize, max: usize, board: &mut Vec<Vec<bool>>) -> bool {
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
    fn solve_helper(current_row: usize, max: usize,  board: &mut Vec<Vec<bool>>, count: &mut i32) {
        for x in 0..max {
            if Self::is_safe(x, current_row, max, board) {
                board[x][current_row] = true;
                if current_row == max-1 {
                    *count = *count + 1;
                } else {
                    Self::solve_helper(current_row + 1, max, board, count);
                }
                board[x][current_row] = false;
            }
        }      
    }
    pub fn total_n_queens(n: i32) -> i32 {
        // Uncomment the following lines to use the lookup table for n = 1 to 9 to gain execution speed
        /* if 1 <= n && n <= 9 {
            return [1, 0, 0, 2, 10, 4, 40, 92, 352][n as usize - 1];
        } */
        
        // Backtracking solutio    
        let mut board = vec![vec![false;n as usize];n as usize];
        let mut count: i32 = 0;
        Self::solve_helper(0usize, n as usize, &mut board, &mut count);
        count
    }
}
