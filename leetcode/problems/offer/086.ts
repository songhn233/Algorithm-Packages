function partition(s: string): string[][] {
  const ans: string[][] = [],
    n = s.length
  const f: boolean[][] = Array(n)
    .fill(0)
    .map((_) => Array(s.length).fill(false))
  for (let i = 0; i < n; i++) f[i][i] = true
  for (let len = 2; len <= n; len++) {
    for (let i = 0; i < n - len + 1; i++) {
      const j = i + len - 1
      if (s[i] === s[j]) {
        if (len <= 2) {
          f[i][j] = true
        } else {
          f[i][j] = f[i + 1][j - 1]
        }
      }
    }
  }
  const dfs = (cur: number, tmp: string[]) => {
    if (cur >= s.length) {
      ans.push(tmp.slice())
      return
    }
    for (let i = cur; i < s.length; i++) {
      if (f[cur][i]) {
        tmp.push(s.slice(cur, i + 1))
        dfs(i + 1, tmp)
        tmp.pop()
      }
    }
  }
  dfs(0, [])
  return ans
}
