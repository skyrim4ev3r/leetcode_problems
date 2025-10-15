class Solution:
    def minimumArea(self, grid: List[List[int]]) -> int:
        max_i = 0
        min_i = len(grid)
        max_j = 0
        min_j = len(grid[0])

        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    max_i = max(max_i, i)
                    min_i = min(min_i, i)

                    max_j = max(max_j, j)
                    min_j = min(min_j, j)

        if max_i < min_i:
            return 0

        return (max_i - min_i + 1) * (max_j - min_j + 1)
