function maxSlidingWindow(nums: number[], k: number): number[] {
  let l = 0,
    r = -1
  const n = nums.length,
    q: number[] = Array(n).fill(0)
  const ans: number[] = []
  for (let i = 0; i < n; i++) {
    if (i >= k) {
      if (q[l] < i - k + 1) {
        l++
      }
    }
    while (r - l + 1 >= 1 && nums[q[r]] <= nums[i]) {
      r--
    }
    q[++r] = i
    if (i >= k - 1) {
      ans.push(nums[q[l]])
    }
  }
  return ans
}
