function spiralOrder(matrix: number[][]): number[] {
  const n = matrix.length,
    m = matrix[0].length
  const ans: number[] = []
  let tot = n * m
  let x = 0,
    y = 0
  const dx = [1, 0, -1, 0],
    dy = [0, 1, 0, -1]
  const vis = Array(n)
    .fill(0)
    .map(() => Array(m).fill(false))
  const check = (x: number, y: number) =>
    x >= 0 && x < m && y >= 0 && y < n && !vis[x][y]
  let cur = 0
  while (tot--) {
    vis[y][x] = true
    ans.push(matrix[y][x])
    let nx = x + dx[cur],
      ny = y + dy[cur]
    if (!check(nx, ny)) {
      cur = (cur + 1) % 4
      ;(nx = x + dx[cur]), (ny = y + dy[cur])
    }
    ;(x = nx), (y = ny)
  }
  return ans
}
