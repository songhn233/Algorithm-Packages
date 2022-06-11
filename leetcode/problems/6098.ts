function countSubarrays(nums: number[], k: number): number {
  const n = nums.length,
    sum = Array(n).fill(0)
  for (let i = 0; i < n; i++) {
    if (i === 0) sum[i] = nums[i]
    else sum[i] = sum[i - 1] + nums[i]
  }
  let l = 0,
    r = 0,
    tmp = 0,
    ans = 0
  for (r = 0; r < n; r++) {
    if (r - 1 >= 0) tmp += sum[r - 1] - (l === 0 ? 0 : sum[l - 1])
    tmp += (r - l + 1) * nums[r]
    while (tmp >= k) {
      tmp -= nums[l] * (r - l + 1)
      tmp -= sum[r] - sum[l]
      l++
    }
    if (tmp < k) {
      ans += r - l + 1
    }
  }
  return ans
}
