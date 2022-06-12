function distributeCookies(cookies: number[], k: number): number {
  cookies.sort((a, b) => b - a)
  let ans = Infinity
  const dfs = (step: number, list: number[]) => {
    if (step >= cookies.length) {
      ans = Math.min(ans, Math.max(...list))
      return
    }
    for (let i = 0; i < k; i++) {
      list[i] += cookies[step]
      dfs(step + 1, list)
      list[i] -= cookies[step]
    }
  }
  dfs(0, Array(k).fill(0))
  return ans
}
