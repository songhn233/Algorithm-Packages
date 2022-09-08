function combinationSum3(k: number, n: number): number[][] {
  const ans: number[][] = []
  const dfs = (sum: number, tmp: number[], last: number) => {
    if (sum > n) {
      return
    }
    if (tmp.length === k) {
      if (sum === n) {
        ans.push(tmp.slice())
      }
      return
    }
    for (let i = last; i <= 9 - (k - tmp.length) + 1; i++) {
      tmp.push(i)
      dfs(sum + i, tmp, i + 1)
      tmp.pop()
    }
  }
  dfs(0, [], 1)
  return ans
}
