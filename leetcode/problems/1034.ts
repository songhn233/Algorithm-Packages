function colorBorder(
  grid: number[][],
  row: number,
  col: number,
  color: number
): number[][] {
  const n = grid.length,
    m = grid[0].length
  const vis = Array(grid.length)
    .fill(0)
    .map((_) => Array(grid[0].length).fill(false))
  const dx = [0, 0, 1, -1],
    dy = [1, -1, 0, 0]
  const ans: number[][] = []
  const check = (x: number, y: number) => {
    if (x < 0 || x >= n || y < 0 || y >= m || vis[x][y]) {
      return false
    }
  }
  const dfs = (x: number, y: number) => {
    vis[x][y] = true
    for (let i = 0; i < 4; i++) {
      const tx = x + dx[i],
        ty = y + dy[i]
      if (tx < 0 || tx >= n || ty < 0 || ty >= m) {
        ans.push([x, y])
        continue
      }
      if (vis[tx][ty]) continue
      if (grid[tx][ty] !== grid[x][y]) {
        ans.push([x, y])
        continue
      }
      dfs(tx, ty)
    }
  }
  dfs(row, col)
  ans.forEach(([x, y]) => (grid[x][y] = color))
  return grid
}
