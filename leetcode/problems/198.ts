function rob(nums: number[]): number {
  const n = nums.length,
    f = Array(n).fill(0)
  ;(f[0] = nums[0]), (f[1] = Math.max(nums[0], nums[1]))
  for (let i = 2; i < n; i++) {
    f[i] = Math.max(f[i - 2] + nums[i], f[i - 1])
  }
  return f[n - 1]
}
