function numSquares(n: number): number {
  const nums: number[] = []
  const f = Array(n + 1).fill(Infinity)
  f[0] = 0
  let i = 1
  while (i * i <= n) {
    nums.push(i * i)
    ++i
  }
  for (let i = 0; i < nums.length; i++) {
    for (let j = nums[i]; j <= n; j++) {
      f[j] = Math.min(f[j], f[j - nums[i]] + 1)
    }
  }
  return f[n]
}
