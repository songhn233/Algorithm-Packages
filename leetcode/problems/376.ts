const wiggleMaxLength = (nums: number[]): number => {
  if (nums.length === 1) return 1
  if (nums.length === 2) return nums[0] === nums[1] ? 1 : 2
  const n = nums.length
  let pre = 0,
    ans = 0
  for (let i = 1; i < n; i++) {
    const diff = nums[i] - nums[i - 1]
    if (!diff) {
      ans++
      continue
    }
    if (diff * pre > 0) {
      ans++
    } else {
      pre = diff
    }
  }
  return n - ans
}
