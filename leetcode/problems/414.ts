function thirdMax(nums: number[]): number {
  nums.sort((a, b) => b - a)
  for (let i = 1, c = 0; i < nums.length; i++) {
    if (nums[i] !== nums[i - 1] && ++c === 2) {
      return nums[i]
    }
  }
  return nums[0]
}
