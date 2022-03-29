function minSubArrayLen(target: number, nums: number[]): number {
  const n = nums.length
  let l = 0,
    r = 0,
    sum = 0,
    ans = n + 1
  while (r < n) {
    sum += nums[r++]
    while (sum >= target) {
      ans = Math.min(ans, r - l)
      sum -= nums[l++]
    }
  }
  return ans === n + 1 ? 0 : ans
}
