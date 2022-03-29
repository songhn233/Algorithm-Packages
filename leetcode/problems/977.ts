function sortedSquares(nums: number[]): number[] {
  const n = nums.length
  let l = 0,
    r = n - 1
  const ans: number[] = []
  while (l <= r) {
    if (nums[l] * nums[l] >= nums[r] * nums[r]) {
      ans.push(nums[l] * nums[l])
      ++l
    } else {
      ans.push(nums[r] * nums[r])
      --r
    }
  }
  return ans.reverse()
}
