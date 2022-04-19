function shortestToChar(s: string, c: string): number[] {
  const N = s.length
  const ans = Array(s.length).fill(-1)
  const check = (idx: number) => idx >= 0 && idx <= s.length && ans[idx] === -1
  const q = []
  for (let i = 0; i < s.length; i++) {
    if (s[i] === c) {
      ans[i] = 0
      q.push(i)
    }
  }
  while (q.length) {
    let tmp = q.length
    while (tmp--) {
      const idx = q.shift()
      if (check(idx - 1)) {
        q.push(idx - 1), (ans[idx - 1] = ans[idx] + 1)
      }
      if (check(idx + 1)) {
        q.push(idx + 1), (ans[idx + 1] = ans[idx] + 1)
      }
    }
  }
  return ans
}
