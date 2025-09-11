#
#        we use n*n board of bools to represent chess board:
#            true  => there is queen on that square
#            false => square is free
#
class Solution:
    # checking if adding queen to this square will hit previous added queens or not
    def is_safe(self, x: int, y: int, max: int, board):
        for ofs in range(0,max): 
            if x  >= ofs and y >= ofs and board[x-ofs][y-ofs]:
                return False
            if x + ofs < max and y >= ofs and board[x + ofs][y - ofs]:
                return False
            if y >= ofs and board[x][y - ofs]:
                return False
        return True
        
    # when we finally place all of our queens on the board then we need to save current board
    def add_board_state_into_res(self, max_row, board, res):
        v = []
        for y in range(max_row):
            tmp = ""
            for x in range(max_row):
                if board[x][y]:
                    v.append("." * x + "Q" + "." * (max_row - x -1))
        res.append(v)

    def solve_helper(self, current_row, max_row,  board, res):
        for x in range(max_row):
            if self.is_safe(x, current_row, max_row, board):
                board[x][current_row] = True
                if current_row == max_row - 1:
                    self.add_board_state_into_res(max_row, board, res)
                else:
                    self.solve_helper(current_row + 1, max_row, board, res)
                board[x][current_row] = False

    def solveNQueens(self, n: int) -> List[List[str]]:
    
        # initial n*n board with default false for each element
        board = [[False for _ in range(n)] for _ in range(n)]
        
        res = []
        # starting backtrack with row = 0
        self.solve_helper(0, n, board, res)
        return res
