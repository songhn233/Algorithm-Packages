/*
 * @lc app=leetcode.cn id=1002 lang=javascript
 *
 * [1002] 查找常用字符
 */

// @lc code=start
/**
 * @param {string[]} A
 * @return {string[]}
 */
const commonChars = (A) => {
  const ans = []
  Array.from(A[0]).forEach((item) => {
    if (A.every((t) => t.includes(item))) {
      A = A.map((t) => t.replace(item, ' '))
      ans.push(item)
    }
  })
  return ans
}
// @lc code=end
