function wiggleSort(nums: number[]): void {
  const ans: number[] = [],
    n = nums.length
  nums.sort((a, b) => a - b)
  const mid = Math.floor((n + 1) / 2)
  let l = mid - 1,
    r = n - 1
  for (let i = 0; i < n; i++) {
    if (i & 1) {
      ans.push(nums[r--])
    } else {
      ans.push(nums[l--])
    }
  }
  for (let i = 0; i < ans.length; i++) nums[i] = ans[i]
}
