/*
 * @lc app=leetcode.cn id=75 lang=javascript
 *
 * [75] 颜色分类
 */

// @lc code=start
/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
const sortColors = (nums) => {
  const map = [0, 0, 0];
  nums.forEach(item => ++ map[item]);
  nums.length = 0;
  Object.keys(map).forEach(item => {
    while(map[item]) {
      nums.push(parseInt(item));
      map[item] --;
    }
  });
};
// @lc code=end

