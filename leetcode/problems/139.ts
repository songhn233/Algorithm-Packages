function wordBreak(s: string, wordDict: string[]): boolean {
  const n = s.length
  const f = Array(n + 1).fill(false),
    set = new Set(wordDict)
  f[0] = true
  for (let i = 1; i <= n; i++) {
    for (let j = 0; j < i; j++) {
      if (set.has(s.substr(j, i - j)) && f[j]) {
        f[i] = true
      }
    }
  }
  return f[n]
}
