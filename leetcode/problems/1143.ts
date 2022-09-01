function longestCommonSubsequence(text1: string, text2: string): number {
  const n = text1.length,
    m = text2.length
  const f = Array(n + 1)
    .fill(0)
    .map((_) => Array(m + 1).fill(0))
  for (let i = 1; i <= n; i++) {
    for (let j = 1; j <= m; j++) {
      f[i][j] = Math.max(f[i - 1][j], f[i][j - 1])
      if (text1[i - 1] === text2[j - 1])
        f[i][j] = Math.max(f[i][j], f[i - 1][j - 1] + 1)
    }
  }
  return f[n][m]
}
