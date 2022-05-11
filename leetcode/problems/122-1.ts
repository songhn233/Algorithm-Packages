const maxProfit = (prices: number[]) => {
  const n = prices.length,
    f = Array(n).fill([0, 0])
  f[0] = [-prices[0], 0]
  for (let i = 1; i < n; i++) {
    f[i] = [
      Math.max(f[i - 1][0], f[i - 1][1] - prices[i]),
      Math.max(f[i - 1][1], f[i - 1][0] + prices[i]),
    ]
  }
  return f[n - 1][1]
}
