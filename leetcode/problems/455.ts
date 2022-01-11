const findContentChildren = (g: number[], s: number[]): number => {
  g.sort((a, b) => a - b)
  s.sort((a, b) => a - b)
  let pos = 0,
    ans = 0
  const n = s.length - 1
  for (let v of g) {
    while (pos < n && s[pos] < v) {
      ++pos
    }
    if (s[pos] >= v) {
      ++pos
      ++ans
    } else {
      break
    }
  }
  return ans
}
