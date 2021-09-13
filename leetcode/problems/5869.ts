function maxProduct(s: string): number {
  let ans = 0
  const check = (c: string) => {
    let l = 0,
      r = c.length - 1
    while (l < r) {
      if (c[l] === c[r]) {
        l++, r--
      } else {
        return false
      }
    }
    return true
  }
  const dfs = (a: string, b: string, idx: number) => {
    if (check(a) && check(b)) {
      ans = Math.max(ans, a.length * b.length)
    }
    if (idx >= s.length) {
      return
    }
    dfs(a + s[idx], b, idx + 1)
    dfs(a, b + s[idx], idx + 1)
    dfs(a, b, idx + 1)
  }
  dfs('', '', 0)
  return ans
}
