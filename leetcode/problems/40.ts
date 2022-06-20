function combinationSum2(candidates: number[], target: number): number[][] {
  const ans: number[][] = []
  candidates.sort((a, b) => a - b)
  const dfs = (cur: number, sum: number, tmp: number[]) => {
    if (sum === target) {
      ans.push(tmp.slice())
      return
    }
    if (sum > target || cur >= candidates.length) {
      return
    }
    for (let i = cur; i < candidates.length; i++) {
      tmp.push(candidates[i])
      dfs(i + 1, sum + candidates[i], tmp)
      tmp.pop()
      while (i + 1 < candidates.length && candidates[i + 1] === candidates[i])
        i++
    }
  }
  dfs(0, 0, [])
  return ans
}
