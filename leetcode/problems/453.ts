function minMoves(nums: number[]): number {
  const minx = nums.reduce((acc, v) => Math.min(acc, v))
  return nums.reduce((acc, v) => acc + v - minx, 0)
}
