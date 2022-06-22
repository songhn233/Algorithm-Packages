function subsets(nums: number[]): number[][] {
  const ans: number[][] = []
  const dfs = (tmp: number[], cur: number) => {
    if (cur >= nums.length) {
      ans.push(tmp.slice())
      return
    }
    tmp.push(nums[cur])
    dfs(tmp, cur + 1)
    tmp.pop()
    dfs(tmp, cur + 1)
  }
  dfs([], 0)
  return ans
}
