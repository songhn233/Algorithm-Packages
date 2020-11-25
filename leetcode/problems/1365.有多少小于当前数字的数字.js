/*
 * @lc app=leetcode.cn id=1365 lang=javascript
 *
 * [1365] 有多少小于当前数字的数字
 */

// @lc code=start
/**
 * @param {number[]} nums
 * @return {number[]}
 */
const smallerNumbersThanCurrent = (nums) => {
  const ans = [],
    map = new Array(101).fill(0)
  for (let i = 0; i < nums.length; i++) {
    map[nums[i]]++
  }
  for (let i = 1; i <= 100; i++) {
    map[i] += map[i - 1]
  }
  for (let i = 0; i < nums.length; i++) {
    ans.push(nums[i] ? map[nums[i] - 1] : 0)
  }
  return ans
}
// @lc code=end
