function combinationSum(candidates: number[], target: number): number[][] {
  const ans: number[][] = []
  const dfs = (d: number, target: number, path: number[]) => {
    if (d >= candidates.length || target < 0) {
      return
    }
    if (target === 0) {
      ans.push(path.slice())
      return
    }
    dfs(d + 1, target, path)
    path.push(candidates[d])
    dfs(d, target - candidates[d], path)
    path.pop()
  }
  dfs(0, target, [])
  return ans
}
