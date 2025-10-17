class Solution:
    def dfs_recursive(self, grid, i, j):

        if grid[i][j] == 0:
            return 0

        total_sum = grid[i][j]
        grid[i][j] = 0

        if i > 0:
            total_sum += self.dfs_recursive(grid, i - 1, j)
        if i < self.rows - 1:
            total_sum += self.dfs_recursive(grid, i + 1, j)

        if j > 0:
            total_sum += self.dfs_recursive(grid, i, j - 1)
        if j < self.cols - 1:
            total_sum += self.dfs_recursive(grid, i, j + 1)

        return total_sum

    def countIslands(self, grid: List[List[int]], k: int) -> int:
        count = 0
        self.rows = len(grid)
        self.cols = len(grid[0])

        for i in range(self.rows):
            for j in range(self.cols):
                if grid[i][j] != 0:
                    total_sum = self.dfs_recursive(grid, i, j)
                    if total_sum % k == 0:
                        count += 1

        return count
