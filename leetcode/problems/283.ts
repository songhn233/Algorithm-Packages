/**
 Do not return anything, modify nums in-place instead.
 */
function moveZeroes(nums: number[]): void {
  let i = 0,
    j = 0
  const n = nums.length
  for (; j < n; j++) {
    if (nums[j] !== 0) {
      nums[i++] = nums[j]
    }
  }
  for (; i < n; i++) {
    nums[i] = 0
  }
}
