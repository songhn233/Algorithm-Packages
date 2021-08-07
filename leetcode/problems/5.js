/**
 * @param {string} s
 * @return {string}
 */
const longestPalindrome = s => {
  const n = s.length
  const f = new Array(n).fill(0).map(_ => new Array(n).fill(false))
  let ans = 0, l = 0, r = 0
  for (let i = 0; i < n; i++) f[i][i] = true
  for (let len = 2; len <= n; len++) {
    for (let i = 0; i < n - len + 1; i++) {
      let j = i + len - 1
      if (s[i] === s[j]) {
        if (j - i + 1 <= 3) f[i][j] = true
        else f[i][j] = f[i + 1][j - 1]
      }
      if (f[i][j] && j - i + 1 > ans) {
        ans = j - i + 1
        l = i, r = j
      }
    }
  }
  return s.slice(l, r + 1)
};