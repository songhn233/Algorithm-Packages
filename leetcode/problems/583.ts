function minDistance(word1: string, word2: string): number {
  const n = word1.length,
    m = word2.length
  const f = Array(n + 1)
    .fill(0)
    .map((_) => Array(m + 1).fill(0))
  for (let i = 1; i <= n; i++) {
    for (let j = 1; j <= m; j++) {
      if (word1[i - 1] === word2[j - 1]) {
        f[i][j] = f[i - 1][j - 1] + 1
      } else {
        f[i][j] = Math.max(f[i - 1][j], f[i][j - 1])
      }
    }
  }
  return n + m - f[n][m] * 2
}
