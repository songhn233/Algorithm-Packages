function maxProfit(prices: number[], fee: number): number {
  const n = prices.length,
    f = Array(n).fill([0, 0])
  f[0] = [-prices[0], 0]
  for (let i = 1; i < n; i++) {
    f[i] = [
      Math.max(f[i - 1][1] - prices[i], f[i - 1][0]),
      Math.max(f[i - 1][0] + prices[i] - fee, f[i - 1][1]),
    ]
  }
  return f[n - 1][1]
}
