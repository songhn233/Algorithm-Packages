/*
 * @lc app=leetcode.cn id=844 lang=javascript
 *
 * [844] 比较含退格的字符串
 */

// @lc code=start
/**
 * @param {string} S
 * @param {string} T
 * @return {boolean}
 */
const backspaceCompare = (S, T) => {
  let a1 = '',
    a2 = ''
  for (let i = 0; i < S.length; i++) {
    if (S[i] === '#' && a1) a1 = a1.substring(0, a1.length - 1)
    else if (S[i] !== '#') a1 += S[i]
  }
  for (let i = 0; i < T.length; i++) {
    if (T[i] === '#' && a2) a2 = a2.substring(0, a2.length - 1)
    else if (T[i] !== '#') a2 += T[i]
  }
  return a1 === a2
}
// @lc code=end
