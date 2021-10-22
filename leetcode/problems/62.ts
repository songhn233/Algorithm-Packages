function uniquePaths(m: number, n: number): number {
  const f = Array(n)
    .fill(0)
    .map((_) => Array(m).fill(0))
  for (let i = 0; i < n; i++) f[i][0] = 1
  for (let j = 0; j < m; j++) f[0][j] = 1
  for (let i = 1; i < n; i++) {
    for (let j = 1; j < m; j++) {
      f[i][j] = f[i - 1][j] + f[i][j - 1]
    }
  }
  return f[n - 1][m - 1]
}
