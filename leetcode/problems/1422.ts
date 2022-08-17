function maxScore(s: string): number {
  const n = s.length,
    s1 = Array(n).fill(0),
    s2 = Array(n).fill(0)
  s1[0] = Number(s[0] === '0')
  for (let i = 1; i < n; i++) {
    s1[i] = s1[i - 1] + Number(s[i] === '0')
  }
  s2[n - 1] = Number(s[n - 1] === '1')
  for (let i = n - 2; i >= 0; i--) {
    s2[i] = s2[i + 1] + Number(s[i] === '1')
  }
  let ans = s1[0] + s2[1]
  for (let i = 0; i < n - 1; i++) {
    ans = Math.max(ans, s1[i] + s2[i + 1])
  }
  return ans
}
