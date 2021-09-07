function coinChange(coins: number[], amount: number): number {
  const inf = 0x3f3f3f3f
  const f = Array(amount + 1).fill(inf)
  f[0] = 0
  for (let i = 0; i < coins.length; i++) {
    for (let v = coins[i]; v <= amount; v++) {
      f[v] = Math.min(f[v], f[v - coins[i]] + 1)
    }
  }
  return f[amount] === inf ? -1 : f[amount]
}
