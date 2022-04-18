function findMaxForm(strs: string[], m: number, n: number): number {
  const f = Array(m + 1)
    .fill(0)
    .map((_) => Array(n + 1).fill(0))
  for (let s of strs) {
    const x = s.split('').filter((i) => i === '0').length,
      y = s.split('').filter((i) => i === '1').length
    for (let i = m; i >= x; i--) {
      for (let j = n; j >= y; j--) {
        f[i][j] = Math.max(f[i][j], f[i - x][j - y] + 1)
      }
    }
  }
  return f[m][n]
}
