/*
 * @lc app=leetcode.cn id=1356 lang=javascript
 *
 * [1356] 根据数字二进制下 1 的数目排序
 */

// @lc code=start
/**
 * @param {number[]} arr
 * @return {number[]}
 */
const calc = (x) => {
  let res = 0
  while (x) {
    if (x & 1) res++
    x = Math.floor(x / 2)
  }
  return res
}
const sortByBits = (arr) => {
  return arr.sort((a, b) => {
    if (calc(a) < calc(b)) return -1
    else if (calc(a) > calc(b)) return 1
    return a - b
  })
}
// @lc code=end
