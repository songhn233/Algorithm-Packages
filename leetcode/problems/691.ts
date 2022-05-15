function minStickers(stickers: string[], target: string): number {
  const m = target.length,
    f = Array(1 << m).fill(-1)
  f[(1 << m) - 1] = 0
  const dfs = (state: number) => {
    if (f[state] === -1) {
      let tmp = m + 1
      for (let sticker of stickers) {
        let up = state
        const map = new Map()
        sticker.split('').forEach((v) => {
          map.set(v, map.has(v) ? map.get(v) + 1 : 1)
        })
        for (let i = 0; i < target.length; i++) {
          const cur = target[i]
          if (((state >> i) & 1) === 0 && map.get(cur)) {
            up |= 1 << i
            map.set(cur, map.get(cur) >= 1 ? map.get(cur) - 1 : 0)
          }
        }
        if (up !== state) {
          tmp = Math.min(tmp, 1 + dfs(up))
        }
      }
      f[state] = tmp
    }
    return f[state]
  }
  const ans = dfs(0)
  return ans <= m ? ans : -1
}
