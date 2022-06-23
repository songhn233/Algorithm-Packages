function subsetsWithDup(nums: number[]): number[][] {
  nums.sort((a, b) => a - b)
  const ans: number[][] = []
  const dfs = (cur: number, tmp: number[]) => {
    ans.push(tmp.slice())
    if (cur >= nums.length) {
      return
    }
    for (let i = cur; i < nums.length; i++) {
      tmp.push(nums[i])
      dfs(i + 1, tmp)
      tmp.pop()
      while (i + 1 < nums.length && nums[i + 1] === nums[i]) {
        i++
      }
    }
  }
  dfs(0, [])
  return ans
}
