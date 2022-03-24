function removeElement(nums: number[], val: number): number {
  let i = 0,
    j = 0
  for (; j < nums.length; j++) {
    if (nums[j] === val) continue
    nums[i++] = nums[j]
  }
  return i
}
