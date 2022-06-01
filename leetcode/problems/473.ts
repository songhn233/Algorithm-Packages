function makesquare(a: number[]) {
  const sum = a.reduce((x, y) => x + y)
  if ((sum / 4) * 4 !== sum) {
    return false
  }
  const t = sum / 4
  a.sort((x, y) => y - x)
  const dfs = (dep: number, arr: number[]) => {
    if (dep >= a.length) {
      return true
    }
    for (let i = 0; i < 4; i++) {
      let flag = false
      for (let j = 0; j < i; j++) {
        if (arr[j] === arr[i]) {
          flag = true
          break
        }
      }
      if (flag) {
        continue
      }
      if (arr[i] + a[dep] > t) {
        continue
      }
      arr[i] += a[dep]
      if (dfs(dep + 1, arr)) {
        return true
      }
      arr[i] -= a[dep]
    }
    return false
  }
  return dfs(0, Array(4).fill(0))
}
