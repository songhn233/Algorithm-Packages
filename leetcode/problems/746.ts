function minCostClimbingStairs(cost: number[]): number {
  const n = cost.length
  const f = Array(n + 1).fill(0)
  cost.push(0)
  ;(f[0] = cost[0]), (f[1] = cost[1])
  for (let i = 2; i <= n; i++) {
    f[i] = cost[i] + Math.min(f[i - 1], f[i - 2])
  }
  return f[n]
}
