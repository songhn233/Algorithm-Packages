function arrayNesting(nums: number[]): number {
  const edges: number[][] = Array(nums.length).fill(0).map(_ => []), n = nums.length
  const vis = Array(nums.length).fill(false)
  nums.forEach((v, i) => {
    edges[i].push(v)
  })
  let ans = 0
  const dfs = (cur: number, s: number[]) => {
    s.push(cur)
    vis[cur] = true
    for(const v of edges[cur]) {
      if(vis[v]) {
        ans = Math.max(ans, s.length)
        continue
      }
      dfs(v, s)
    }
  }
  for(let i = 0; i < n; i ++) {
    if(!vis[i]) {
      dfs(i, [])
    }
  }
  return ans
};