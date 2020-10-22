/*
 * @lc app=leetcode.cn id=763 lang=javascript
 *
 * [763] 划分字母区间
 */

// @lc code=start
/**
 * @param {string} S
 * @return {number[]}
 */
const partitionLabels = (S) => {
  const map = new Map()
  for (let i = 0; i < S.length; i++) {
    if (map.has(S[i])) {
      map.set(S[i], i)
    } else {
      map.set(S[i], i)
    }
  }
  let index = 0,
    pre = 0
  const ans = []
  for (let i = 0; i < S.length; i++) {
    index = Math.max(index, map.get(S[i]))
    if (i >= index) {
      ans.push(i - pre + 1)
      pre = index + 1
      index++
    }
  }
  return ans
}
// @lc code=end
