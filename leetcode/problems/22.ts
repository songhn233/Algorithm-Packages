function generateParenthesis(n: number): string[] {
  const ans: string[] = []
  const dfs = (tmp: string[], t1: number, t2: number) => {
    if (tmp.length === 2 * n) {
      ans.push(tmp.join(''))
      return
    }
    if (t1 < n) {
      tmp.push('(')
      dfs(tmp, t1 + 1, t2)
      tmp.pop()
    }
    if (t2 < t1) {
      tmp.push(')')
      dfs(tmp, t1, t2 + 1)
      tmp.pop()
    }
  }
  dfs([], 0, 0)
  return ans
}
