function isSubsequence(s: string, t: string): boolean {
  let cur = 0
  for (let i = 0; i < t.length; i++) {
    if (t[i] === s[cur]) {
      cur++
    }
    if (cur === s.length) {
      break
    }
  }
  return cur === s.length
}
