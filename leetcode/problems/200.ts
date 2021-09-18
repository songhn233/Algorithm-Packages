function numIslands(grid: string[][]): number {
  const n = grid.length,
    m = grid[0].length
  let ans = 0
  const tx = [0, 0, 1, -1],
    ty = [1, -1, 0, 0]
  const calc = (i: number, j: number) => {
    return (
      i >= 0 && i < n && j >= 0 && j < m && !vis[i][j] && grid[i][j] === '1'
    )
  }
  const dfs = (i: number, j: number) => {
    vis[i][j] = true
    for (let t = 0; t < 4; t++) {
      const dx = tx[t] + i,
        dy = ty[t] + j
      if (calc(dx, dy)) {
        dfs(dx, dy)
      }
    }
  }
  const vis = Array(n)
    .fill(0)
    .map((_) => Array(m).fill(false))
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < m; j++) {
      if (!calc(i, j)) continue
      ans += 1
      dfs(i, j)
    }
  }
  return ans
}
