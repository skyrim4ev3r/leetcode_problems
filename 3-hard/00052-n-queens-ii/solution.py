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

    def solve_helper(self, current_row, max_row,  board, res):
        for x in range(max_row):
            if self.is_safe(x, current_row, max_row, board):
                board[x][current_row] = True
                if current_row == max_row - 1:
                    res[0] += 1
                else:
                    self.solve_helper(current_row + 1, max_row, board, res)
                board[x][current_row] = False

    def totalNQueens(self, n: int) -> int:
        # Uncomment the following lines to use the lookup table for n = 1 to 9 to gain execution speed
        # if 1 <= n <= 9:
        #    return [1, 0, 0, 2, 10, 4, 40, 92, 352][n - 1]

        # Backtracking solutio
        board = [[False for _ in range(n)] for _ in range(n)]
        res = [0]
        self.solve_helper(0, n, board, res)
        return res[0]
