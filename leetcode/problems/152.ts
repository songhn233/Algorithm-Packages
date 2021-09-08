function maxProduct(nums: number[]): number {
  let maxx = nums[0],
    minx = nums[0],
    ans = nums[0]
  for (let i = 1; i < nums.length; i++) {
    let tmaxx = Math.max(maxx * nums[i], Math.max(minx * nums[i], nums[i]))
    let tminx = Math.min(minx * nums[i], Math.min(maxx * nums[i], nums[i]))
    ;(maxx = tmaxx), (minx = tminx)
    ans = Math.max(maxx, ans)
  }
  return ans
}
