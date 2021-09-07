function maxProfit(prices: number[]): number {
  let min = prices[0],
    ans = 0
  for (let i = 1; i < prices.length; i++) {
    ans = Math.max(ans, prices[i] - min)
    min = Math.min(min, prices[i])
  }
  return ans
}
