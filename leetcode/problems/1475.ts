function finalPrices(prices: number[]): number[] {
  const s: number[] = [],
    n = prices.length
  let top = 0
  const ans = prices.slice()
  for (let i = 0; i < n; i++) {
    while (top && prices[s[top]] >= prices[i]) {
      ans[s[top]] = prices[s[top]] - prices[i]
      --top
    }
    s[++top] = i
  }
  return ans
}
