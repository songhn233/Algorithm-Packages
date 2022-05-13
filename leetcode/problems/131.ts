function partition(s: string): string[][] {
  const ans: string[][] = [],
    n = s.length
  const check = (i: number, j: number) => {
    const tmp = s.slice(i, j + 1)
    let x = 0,
      y = j - i,
      flag = true
    while (x < y) {
      if (tmp[x] === tmp[y]) {
        ++x, --y
      } else {
        flag = false
        break
      }
    }
    return flag
  }
  const dfs = (idx: number, res: string[]) => {
    if (idx >= n) {
      ans.push(res.slice())
      return
    }
    for (let i = idx; i < n; i++) {
      if (check(idx, i)) {
        res.push(s.slice(idx, i + 1))
        dfs(i + 1, res)
        res.pop()
      }
    }
  }
  dfs(0, [])
  return ans
}
