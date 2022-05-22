function canIWin(maxChoosableInteger: number, desiredTotal: number): boolean {
  if ((maxChoosableInteger + 1) * maxChoosableInteger < desiredTotal * 2) {
    return false
  }
  const f = Array(1 << maxChoosableInteger).fill(undefined)
  const dfs = (cur: number, tot: number) => {
    if (f[cur] !== undefined) {
      return f[cur]
    }
    for (let i = 0; i < maxChoosableInteger; i++) {
      if (((cur >> i) & 1) === 0) {
        if (tot + i + 1 >= desiredTotal) {
          return (f[cur] = true)
        } else {
          if (dfs(cur | (1 << i), tot + i + 1) === false) {
            return (f[cur] = true)
          }
        }
      }
    }
    return (f[cur] = false)
  }
  return dfs(0, 0)
}
