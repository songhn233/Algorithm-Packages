function minCost(costs: number[][]): number {
  const n = costs.length,
    f = Array(n)
      .fill(0)
      .map((_) => [Infinity, Infinity, Infinity])
  for (let i = 0; i < 3; i++) f[0][i] = costs[0][i]
  for (let i = 1; i < n; i++) {
    for (let j = 0; j < 3; j++) {
      for (let k = 0; k < 3; k++) {
        if (j === k) {
          continue
        }
        f[i][j] = Math.min(f[i][j], f[i - 1][k] + costs[i][j])
      }
    }
  }
  return Math.min(...f[n - 1])
}
