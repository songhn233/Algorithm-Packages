function restoreIpAddresses(s: string): string[] {
  const ans: string[] = []
  const check = (str: string) => {
    if (String(Number(str)) !== str) {
      return false
    }
    const x = Number(str)
    return x >= 0 && x <= 255
  }
  const dfs = (step: number, cur: number, tmp: string[]) => {
    if (step >= 4) {
      if (cur >= s.length) ans.push(tmp.join('.'))
      return
    }
    for (let i = cur; i < s.length; i++) {
      if (check(s.slice(cur, i + 1))) {
        tmp.push(s.slice(cur, i + 1))
        dfs(step + 1, i + 1, tmp)
        tmp.pop()
      }
    }
  }
  dfs(0, 0, [])
  return ans
}
