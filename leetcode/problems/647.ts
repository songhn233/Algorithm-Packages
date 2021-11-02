function countSubstrings(s: string): number {
  const n = s.length
  let ans = 0
  for (let i = 0; i < 2 * n - 2; i++) {
    let x = Math.floor(i / 2),
      y = x + 1
    while (x >= 0 && y < n && s[x] === s[y]) {
      ans++, x--, y++
    }
  }
  return ans
}
