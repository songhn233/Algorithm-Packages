function findNumberOfLIS(nums: number[]): number {
  const n = nums.length
  const f = Array(n).fill(1),
    cnt = Array(n).fill(1)
  let ans = 0,
    tot = 0
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < i; j++) {
      if (nums[j] < nums[i]) {
        if (f[j] + 1 > f[i]) {
          f[i] = f[j] + 1
          cnt[i] = cnt[j]
        } else if (f[j] + 1 === f[i]) {
          cnt[i] += cnt[j]
        }
      }
    }
    if (f[i] > ans) {
      ans = f[i]
      tot = cnt[i]
    } else if (f[i] === ans) {
      tot += cnt[i]
    }
  }
  return tot
}
