function findSubstring(s: string, words: string[]): number[] {
  const m = words[0].length,
    n = s.length
  let l = 0
  const mp = new Map()
  const init = () => {
    mp.clear()
    words.forEach((w) => {
      if (mp.has(w)) {
        mp.set(w, mp.get(w) + 1)
      } else {
        mp.set(w, 1)
      }
    })
  }
  init()
  const ans: number[] = []
  for (let cur = 0; cur < m; cur++) {
    l = cur
    init()
    for (let r = m - 1 + cur; r < n; r += m) {
      const tmp = s.slice(r - m + 1, r + 1)
      if (mp.has(tmp)) {
        if (mp.get(tmp) <= 0) {
          while (mp.get(tmp) <= 0) {
            const t = s.slice(l, l + m)
            mp.set(t, mp.get(t) + 1)
            l += m
          }
        }
        mp.set(tmp, mp.get(tmp) - 1)
        if ([...mp.values()].every((v) => v === 0)) {
          ans.push(l)
        }
      } else {
        while (l < r) {
          const t = s.slice(l, l + m)
          if (mp.has(t)) mp.set(t, mp.get(t) + 1)
          l += m
        }
      }
    }
  }
  return ans
}
