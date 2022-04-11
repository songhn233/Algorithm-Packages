function integerBreak(n: number): number {
  const f = Array(n + 1).fill(0)
  f[2] = 1
  for (let i = 3; i <= n; i++) {
    for (let j = 1; j < i; j++) {
      f[i] = Math.max(f[i], (i - j) * j, f[i - j] * j)
    }
  }
  return f[n]
}
