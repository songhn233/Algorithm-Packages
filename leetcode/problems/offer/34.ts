function searchRange(nums: number[], target: number): number[] {
  const ans = []
  let l = 0,
    r = nums.length - 1
  while (l < r) {
    const mid = (l + r) >> 1
    if (nums[mid] >= target) r = mid
    else l = mid + 1
  }
  ans.push(nums[l] === target ? l : -1)
  ;(l = 0), (r = nums.length - 1)
  while (l < r) {
    const mid = (l + r + 1) >> 1
    if (nums[mid] <= target) l = mid
    else r = mid - 1
  }
  ans.push(nums[l] === target ? l : -1)
  return ans
}
