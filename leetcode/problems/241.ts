function diffWaysToCompute(s: string): number[] {
  const n = s.length
  const dfs = (l: number, r: number) => {
    const ans: number[] = []
    for(let i = l; i <= r; i ++) {
      const t = s[i]
      if(t >= '0' && t <= '9') {
        continue
      }
      const x = dfs(l, i - 1), y = dfs(i + 1, r)
      for(let a of x) {
        for(let b of y) {
          if(t === '-') {
            ans.push(a - b)
          } else if (t === '+') {
            ans.push(a + b)
          } else {
            ans.push(a * b)
          }
        }
      }
    }
    if(ans.length === 0) {
      ans.push(Number(s.slice(l, r + 1)))
    }
    return ans
  }
  return dfs(0, n - 1)
}