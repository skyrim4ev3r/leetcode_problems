class Solution:
    def backtrack(self, grid, i, j):

        if grid[i][j] == 0:
            return 0

        total_sum = grid[i][j]
        grid[i][j] = 0

        if i > 0:
            total_sum += self.backtrack(grid, i - 1, j)
        if i < len(grid) - 1:
            total_sum += self.backtrack(grid, i + 1, j)

        if j > 0:
            total_sum += self.backtrack(grid, i, j - 1)
        if j < len(grid[i]) - 1:
            total_sum += self.backtrack(grid, i, j + 1)

        return total_sum

    def countIslands(self, grid: List[List[int]], k: int) -> int:
        count = 0

        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j] != 0:
                    total_sum = self.backtrack(grid, i, j)
                    if total_sum % k == 0:
                        count += 1

        return count
