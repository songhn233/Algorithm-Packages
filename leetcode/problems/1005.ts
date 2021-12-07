function largestSumAfterKNegations(nums: number[], k: number): number {
  let min = Number.MAX_VALUE
  nums.sort((a, b) => a - b)
  let sum = nums.reduce((p, v) => p + v)
  for (let i = 0; i < nums.length; i++) {
    if (k <= 0) break
    if (nums[i] < 0) {
      nums[i] = -nums[i]
      sum += 2 * nums[i]
      --k
    }
    min = Math.min(min, nums[i])
  }
  if (k & 1) {
    sum -= 2 * min
  }
  return sum
}
