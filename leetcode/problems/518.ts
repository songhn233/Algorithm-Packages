function change(amount: number, coins: number[]): number {
  const f = Array(amount + 1).fill(0)
  f[0] = 1
  for (let i = 0; i < coins.length; i++) {
    for (let j = coins[i]; j <= amount; j++) {
      f[j] += f[j - coins[i]]
    }
  }
  return f[amount]
}
