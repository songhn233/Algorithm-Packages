const MOD = 1e9 + 7
function countPalindromicSubsequences(s: string) {
  const n = s.length,
    f = Array(n)
      .fill(0)
      .map((_) => Array(n).fill(0))
  for (let i = 0; i < n; i++) f[i][i] += 1
  for (let len = 2; len <= n; len++) {
    const arr = Array(4)
      .fill(0)
      .map((_) => [])
    for (let i = 0; i < n; i++) {
      arr[s[i].charCodeAt(0) - 'a'.charCodeAt(0)].push(i)
      const j = i - len + 1
      if (j >= 0) {
        for (let k = 0; k < 4; k++) {
          const q = arr[k]
          while (q.length && q[0] < j) {
            q.shift()
          }
          if (q.length) {
            const l = q[0],
              r = q[q.length - 1]
            if (l == r) f[j][i] = (f[j][i] + 1) % MOD
            else {
              f[j][i] = (f[j][i] + f[l + 1][r - 1] + 2) % MOD
            }
          }
        }
      }
    }
  }
  return f[0][n - 1] % MOD
}
