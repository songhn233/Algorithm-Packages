/*
 * @lc app=leetcode.cn id=52 lang=javascript
 *
 * [52] N皇后 II
 */

// @lc code=start
/**
 * @param {number} n
 * @return {number}
 */
function dfs(d, n, col, dial, diar) {
  if (d === n) {
    return 1
  }
  let ans = 0
  for (let i = 0; i < n; i++) {
    if (col.has(i) || dial.has(d - i) || diar.has(d + i)) {
      continue
    }
    col.add(i)
    dial.add(d - i)
    diar.add(d + i)
    ans += dfs(d + 1, n, col, dial, diar)
    col.delete(i)
    dial.delete(d - i)
    diar.delete(d + i)
  }
  return ans
}
const totalNQueens = (n) => {
  const col = new Set(),
    dial = new Set(),
    diar = new Set()
  return dfs(0, n, col, dial, diar)
}
// @lc code=end
