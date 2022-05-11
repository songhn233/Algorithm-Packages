const maxProfit = (prices: number[]) =>
  prices.reduceRight(
    ([ans, maxn], cur) => [Math.max(maxn - cur, ans), Math.max(maxn, cur)],
    [0, 0]
  )[0]
