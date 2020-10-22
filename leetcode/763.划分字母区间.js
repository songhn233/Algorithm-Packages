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
const calc = (S, index) => {
  const map = new Map()
  for (let i = index; i < S.length; i++) {
    if (map.has(S[i])) {
      map.set(S[i], i)
    } else {
      map.set(S[i], i)
    }
  }
  let ans = index
  for (let i = index; i < S.length; i++) {
    if (i <= ans) ans = Math.max(ans, map.get(S[i]))
  }
  return ans
}
const partitionLabels = (S) => {
  let index = 0,
    pre = 0
  const ans = []
  while (index < S.length) {
    index = calc(S, index)
    ans.push(index - pre + 1)
    index++
    pre = index
  }
  return ans
}
// @lc code=end
