/*
 * @lc app=leetcode.cn id=406 lang=javascript
 *
 * [406] 根据身高重建队列
 */

// @lc code=start
/**
 * @param {number[][]} people
 * @return {number[][]}
 */
const reconstructQueue = (people) => {
  const list = people.sort((a, b) => {
    if (a[0] > b[0]) return -1
    else if (a[0] < b[0]) return 1
    else return a[1] < b[1] ? -1 : 1
  })
  const ans = []
  list.forEach((v) => {
    if (v[1] >= ans.length) {
      ans.push(v)
    } else {
      ans.splice(v[1], 0, v)
    }
  })
  return ans
}
// @lc code=end
