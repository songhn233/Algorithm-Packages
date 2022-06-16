function smallestDistancePair(nums: number[], k: number): number {
  nums.sort((a, b) => a - b)
  const n = nums.length
  let l = 0,
    r = nums[n - 1] - nums[0]
  const check = (x: number) => {
    let sum = 0
    for (let i = 0, j = 0; j < n; j++) {
      while (nums[j] - nums[i] > x) ++i
      sum += j - i
    }
    return sum
  }
  while (l < r) {
    const mid = (l + r) >> 1
    if (check(mid) >= k) r = mid
    else l = mid + 1
  }
  return l
}
