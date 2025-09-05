#https://leetcode.com/problems/flip-square-submatrix-vertically/
class Solution:
    def reverseSubmatrix(self, grid: List[List[int]], x: int, y: int, k: int) -> List[List[int]]:
        for j in range(0,k):
            for i in range(0,k//2):
                tmp = grid[x+i][y+j]
                grid[x+i][y+j] = grid[x+k-i-1][y+j]
                grid[x+k-i-1][y+j] = tmp
        return grid

