function shoppingOffers(
  price: number[],
  special: number[][],
  needs: number[]
): number {
  const map = new Map<string, number>()
  const toString = (x: number[]) => x.join(',')
  const n = needs.length
  const dfs = (needs: number[]) => {
    if (map.has(toString(needs))) {
      return map.get(toString(needs))
    }
    let ans = 0
    for (let i = 0; i < needs.length; i++) {
      ans += needs[i] * price[i]
    }
    for (let i = 0; i < special.length; i++) {
      const nex: number[] = []
      for (let j = 0; j < n; j++) {
        if (special[i][j] > needs[j]) {
          break
        }
        nex.push(needs[j] - special[i][j])
      }
      if (nex.length >= n) {
        ans = Math.min(ans, dfs(nex) + special[i][n])
      }
    }
    map.set(toString(needs), ans)
    return ans
  }
  return dfs(needs)
}
