function combine(n: number, k: number): number[][] {
  const ans: number[][] = []
  const dfs = (d: number, tmp: number[], last: number) => {
    if (d >= k) {
      ans.push(tmp.slice())
      return
    }
    for (let i = last; i < n; i++) {
      tmp.push(i + 1)
      dfs(d + 1, tmp, i + 1)
      tmp.pop()
    }
  }
  dfs(0, [], 0)
  return ans
}
