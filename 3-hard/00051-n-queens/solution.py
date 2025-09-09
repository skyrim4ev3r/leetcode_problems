class Solution:
    def is_safe(self, x: int, y: int, max: int, board):
        for ofs in range(0,max): 
            if x  >= ofs and y >= ofs and board[x-ofs][y-ofs]:
                return False
            if x + ofs < max and y >= ofs and board[x + ofs][y - ofs]:
                return False
            if y >= ofs and board[x][y - ofs]:
                return False
        return True

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
        board = [[False for _ in range(n)] for _ in range(n)]
        res = []
        self.solve_helper(0, n, board, res)
        return res
