const minMoves2 = (nums: number[]) => {
  nums.sort((a, b) => a - b)
  const base = nums[Math.ceil((nums.length - 1) / 2)]
  return nums.reduce((ans, v) => ans + Math.abs(v - base), 0)
}
