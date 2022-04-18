function lastStoneWeightII(stones: number[]): number {
  const m = stones.reduce((a, b) => a + b),
    f = Array(m).fill(0),
    n = stones.length
  const max = (a: number, b: number) => (a > b ? a : b)
  for (let i = 0; i < n; i++) {
    for (let j = m; j >= stones[i]; j--) {
      f[j] = max(f[j], f[j - stones[i]] + stones[i])
    }
  }
  return Math.abs(m - 2 * f[Math.floor(m / 2)])
}
