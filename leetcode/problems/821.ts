function shortestToChar(s: string, c: string): number[] {
  const ans = Array(s.length).fill(s.length)
  for (let i = 0, j = -1; i < s.length; i++) {
    if (s[i] === c) j = i
    if (j !== -1) ans[i] = i - j
  }
  for (let i = s.length - 1, j = s.length; i >= 0; i--) {
    if (s[i] === c) j = i
    if (j !== s.length) ans[i] = ans[i] > j - i ? j - i : ans[i]
  }
  return ans
}
