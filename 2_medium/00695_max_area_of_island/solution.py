class Solution:
    def backtrack(self, grid, i, j):
        if grid[i][j] == 0:
            return

        self.count += 1
        grid[i][j] = 0

        if i > 0:
            self.backtrack(grid, i - 1, j)

        if i < len(grid) - 1:
            self.backtrack(grid, i + 1, j)

        if j > 0:
            self.backtrack(grid, i, j - 1)

        if j < len(grid[i]) - 1:
            self.backtrack(grid, i, j + 1)

    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        max_area = 0
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j] == 1:
                    self.count = 0
                    self.backtrack(grid, i, j)
                    max_area = max(max_area, self.count)

        return max_area
