function minDistance(word1: string, word2: string): number {
  const n = word1.length,
    m = word2.length
  const f = Array(n + 1)
    .fill(0)
    .map((_) => Array(m + 1).fill(0))
  for (let i = 0; i <= n; i++) f[i][0] = i
  for (let j = 0; j <= m; j++) f[0][j] = j
  for (let i = 1; i <= n; i++) {
    for (let j = 1; j <= m; j++) {
      f[i][j] = Math.min(
        f[i][j - 1] + 1,
        f[i - 1][j] + 1,
        f[i - 1][j - 1] + (word1[i - 1] === word2[j - 1] ? 0 : 1)
      )
    }
  }
  return f[n][m]
}
