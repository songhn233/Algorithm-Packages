function findTargetSumWays(nums: number[], target: number): number {
  const sum = nums.reduce((a, b) => a + b)
  if (Math.abs(target) > sum || (target + sum) & 1) {
    return 0
  }
  const v = (target + sum) / 2,
    n = nums.length,
    m = sum,
    f = Array(m + 1).fill(0)
  f[0] = 1
  for (let i = 0; i < n; i++) {
    for (let j = m; j >= nums[i]; j--) {
      f[j] += f[j - nums[i]]
    }
  }
  return f[v]
}
