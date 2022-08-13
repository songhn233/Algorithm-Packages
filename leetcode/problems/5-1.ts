function longestPalindrome(s: string): string {
  let ans = 1,
    str = s[0],
    n = s.length
  for (let i = 0; i < n * 2 - 1; i++) {
    let l = Math.floor(i / 2),
      r = Math.floor(i / 2) + (i % 2)
    while (l >= 0 && r < n && s[l] === s[r]) {
      if (r - l + 1 > ans) {
        ans = r - l + 1
        str = s.slice(l, r + 1)
      }
      l--, r++
    }
  }
  return str
}
