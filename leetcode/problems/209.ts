function minSubArrayLen(target: number, nums: number[]): number {
  nums.unshift(0)
  const n = nums.length
  const sum = Array(n).fill(0)
  let ans = -1
  for (let i = 1; i < n; i++) {
    sum[i] = sum[i - 1] + nums[i]
  }
  for (let i = 1; i < n; i++) {
    if (sum[n - 1] - sum[i - 1] < target) continue
    let l = i,
      r = n - 1
    while (l < r) {
      let mid = (l + r) >> 1
      if (sum[mid] - sum[i - 1] >= target) r = mid
      else l = mid + 1
    }
    ans = ans === -1 ? l - i + 1 : Math.min(ans, l - i + 1)
  }
  return ans === -1 ? 0 : ans
}
