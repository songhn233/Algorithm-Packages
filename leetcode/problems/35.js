/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
const searchInsert = function (nums, target) {
  const n = nums.length
  let l = 0,
    r = n - 1
  while (l < r) {
    const mid = (l + r) >> 1
    if (nums[mid] >= target) r = mid
    else l = mid + 1
  }
  return nums[l] >= target ? l : n
}
