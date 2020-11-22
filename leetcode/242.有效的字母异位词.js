/*
 * @lc app=leetcode.cn id=242 lang=javascript
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
const isAnagram = (s, t) => {
  const map = new Map()
  s.split('').forEach((v) => {
    map.set(v, (map.get(v) ? map.get(v) : 0) + 1)
  })
  let ans = true
  t.split('').forEach((v) => {
    if (!map.has(v)) {
      ans = false
    }
    map.set(v, map.get(v) - 1)
  })
  s.split('').forEach((v) => {
    if (map.get(v)) {
      ans = false
    }
  })
  t.split('').forEach((v) => {
    if (map.get(v)) {
      ans = false
    }
  })
  return ans
}
// @lc code=end
