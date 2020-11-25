/*
 * @lc app=leetcode.cn id=1 lang=javascript
 *
 * [1] 两数之和
 */

// @lc code=start
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
  const map = new Map();
  const ans = [];
  nums.forEach((item, index) => {
    if (map.get(target - item) !== undefined) {
      if (!ans.length) {
        ans.push(map.get(target - item));
        ans.push(index);
      }
    } else {
      map.set(item, index);
    }
  });
  return ans;
};
// @lc code=end

