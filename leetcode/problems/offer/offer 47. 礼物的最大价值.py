class Solution:
    def maxValue(self, grid: List[List[int]]) -> int:
        f = [[0] * len(grid[0]) for i in range(len(grid))]
        f[0][0] = grid[0][0]
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if i - 1 >= 0:
                    f[i][j] = max(f[i][j], f[i-1][j]+grid[i][j])
                if j - 1 >= 0:
                    f[i][j] = max(f[i][j], f[i][j-1]+grid[i][j])
        return f[-1][-1]
