/*
 * @lc app=leetcode.cn id=416 lang=javascript
 *
 * [416] 分割等和子集
 */

// @lc code=start
/**
 * @param {number[]} nums
 * @return {boolean}
 */
const canPartition = (nums) => {
  const sum = nums.reduce((sum, value) => sum + value)
  if (sum % 2) return false
  const f = new Array(sum + 1).fill(0)
  f[0] = 1
  for (let i = 0; i < nums.length; i++) {
    for (let j = sum; j >= nums[i]; j--) {
      f[j] |= f[j - nums[i]]
    }
  }
  return f[sum / 2] ? true : false
}
// @lc code=end
