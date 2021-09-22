function lengthOfLIS(nums: number[]): number {
  const n = nums.length
  const f = Array(n).fill(1)
  let ans = 1
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < i; j++) {
      if (nums[j] < nums[i]) {
        f[i] = Math.max(f[i], f[j] + 1)
      }
    }
    ans = Math.max(ans, f[i])
  }
  return ans
}
