function minSubArrayLen(target: number, nums: number[]): number {
  let current = 0
  let l = 0,
    r = -1,
    ans = Infinity
  while (r < nums.length) {
    r++
    current += nums[r]
    while (current >= target) {
      ans = Math.min(ans, r - l + 1)
      current -= nums[l++]
    }
  }
  return ans === Infinity ? 0 : ans
}
