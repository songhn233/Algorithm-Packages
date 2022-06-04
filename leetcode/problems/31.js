/*
 * @lc app=leetcode.cn id=31 lang=javascript
 *
 * [31] 下一个排列
 */

// @lc code=start
/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
const nextPermutation = (nums) => {
  let x = -1,
    y = -1
  for (let i = nums.length - 2; i >= 0; i--) {
    if (nums[i] < nums[i + 1]) {
      x = i
      break
    }
  }
  if (x != -1) {
    for (let i = nums.length - 1; i >= 0; i--) {
      if (i > x && nums[i] > nums[x]) {
        y = i
        break
      }
    }
  }
  if (x != -1 && y != -1) {
    const temp = nums[x]
    nums[x] = nums[y]
    nums[y] = temp
  }
  const ans = [...nums.slice(0, x + 1), ...nums.splice(x + 1).reverse()]

  ans.forEach((val, index) => {
    nums[index] = val
  })
}
// @lc code=end
