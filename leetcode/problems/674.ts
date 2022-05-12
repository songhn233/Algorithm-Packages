function findLengthOfLCIS(nums: number[]): number {
  const n = nums.length,
    f = Array(n).fill(1)
  for (let i = 1; i < n; i++) {
    f[i] = nums[i] > nums[i - 1] ? f[i - 1] + 1 : f[i]
  }
  return Math.max(...f)
}
