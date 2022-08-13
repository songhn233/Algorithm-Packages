function countSubstrings(s: string): number {
  const n = s.length
  let ans = 0
  for (let i = 0; i < 2 * n - 1; i++) {
    let l = Math.floor(i / 2),
      r = l + (i % 2)
    while (l >= 0 && r < n && s[l] === s[r]) {
      ans++
      l--, r++
    }
  }
  return ans
}
