const minPathCost = (grid: number[][], moveCost: number[][]) => {
  const n = grid.length,
    m = grid[0].length,
    f = Array(n)
      .fill(0)
      .map((_) => Array(m).fill(Infinity))
  for (let i = 0; i < m; i++) f[0][i] = grid[0][i]
  for (let i = 1; i < n; i++) {
    for (let j = 0; j < m; j++) {
      for (let k = 0; k < m; k++) {
        f[i][j] = Math.min(
          f[i][j],
          f[i - 1][k] + moveCost[grid[i - 1][k]][j] + grid[i][j]
        )
      }
    }
  }
  return Math.min(...f[n - 1])
}
