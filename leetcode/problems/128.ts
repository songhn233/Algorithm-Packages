function longestConsecutive(nums: number[]): number {
  const set = new Set()
  nums.forEach((v) => set.add(v))
  let ans = 0
  for (let i = 0; i < nums.length; i++) {
    if (!set.has(nums[i] - 1)) {
      let tmp = nums[i],
        res = 1
      while (set.has(tmp + 1)) {
        tmp += 1
        res += 1
      }
      ans = Math.max(ans, res)
    }
  }
  return ans
}
