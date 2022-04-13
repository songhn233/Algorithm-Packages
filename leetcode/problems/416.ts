function canPartition(nums: number[]): boolean {
  const n = nums.length,
    sum = nums.reduce((a, b) => a + b)
  if (sum & 1) {
    return false
  }
  const f = Array(sum + 1).fill(false)
  f[0] = true
  for (let i = 0; i < n; i++) {
    for (let j = sum; j >= nums[i]; j--) {
      f[j] |= f[j - nums[i]]
    }
  }
  return f[sum / 2]
}
