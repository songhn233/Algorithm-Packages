/*
 * @lc app=leetcode.cn id=771 lang=javascript
 *
 * [771] 宝石与石头
 */

// @lc code=start
/**
 * @param {string} J
 * @param {string} S
 * @return {number}
 */
const numJewelsInStones = function(J, S) {
  const map = {};
  console.log(J.split(''));
  J.split('').forEach(item => {
    map[item] = true;
  });
  let ans = 0;
  S.split('').forEach(item => {
    if (map[item]) {
      ans++;
    };
  });
  return ans;
};
// @lc code=end