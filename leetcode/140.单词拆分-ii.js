/*
 * @lc app=leetcode.cn id=140 lang=javascript
 *
 * [140] 单词拆分 II
 */

// @lc code=start
/**
 * @param {string} s
 * @param {string[]} wordDict
 * @return {string[]}
 */
const wordBreak = (s, wordDict) => {
  const map = new Set(wordDict)
  const vis = new Array(s.length)
  const dfs = (dep) => {
    if (vis[dep]) return vis[dep]
    if (dep >= s.length) return [[]]
    const ans = []
    for (let i = dep; i < s.length; i++) {
      const temp = s.substr(dep, i - dep + 1)
      if (map.has(temp)) {
        const rest = dfs(i + 1)
        rest.forEach((v) => {
          ans.push([temp, ...v])
        })
      }
    }
    vis[dep] = ans
    return ans
  }
  return dfs(0).map((v) => v.join(' '))
}
// @lc code=end
