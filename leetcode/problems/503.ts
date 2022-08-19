function nextGreaterElements(nums: number[]): number[] {
  const n = nums.length,
    ans = Array(n).fill(-1)
  const sta: number[] = []
  let top = -1
  for (let i = 0; i < n * 2; i++) {
    while (top >= 0 && nums[sta[top]] < nums[i % n]) {
      ans[sta[top--]] = nums[i % n]
    }
    sta[++top] = i % n
  }
  return ans
}
