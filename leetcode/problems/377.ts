function combinationSum4(nums: number[], target: number): number {
  const f = Array(target + 1).fill(0),
    n = nums.length
  f[0] = 1
  for (let i = 0; i <= target; i++) {
    for (let j = 0; j < n; j++) {
      if (i >= nums[j]) f[i] += f[i - nums[j]]
    }
  }
  return f[target]
}