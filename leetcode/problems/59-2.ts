function generateMatrix(n: number): number[][] {
  const ans = Array(n)
    .fill(0)
    .map((_) => Array(n).fill(0))
  const vis = Array(n)
    .fill(0)
    .map((_) => Array(n).fill(false))
  let x = 0,
    y = 0,
    cur = 0,
    tot = n * n
  const dx = [0, 1, 0, -1],
    dy = [1, 0, -1, 0]
  const check = (x: number, y: number) =>
    x >= 0 && x < n && y >= 0 && y < n && !vis[x][y]
  for (let i = 1; i <= tot; i++) {
    ;(vis[x][y] = true), (ans[x][y] = i)
    if (!check(x + dx[cur], y + dy[cur])) {
      cur = (cur + 1) % 4
    }
    ;(x += dx[cur]), (y += dy[cur])
  }
  return ans
}
