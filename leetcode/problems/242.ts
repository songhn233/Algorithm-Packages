function isAnagram(s: string, t: string): boolean {
  if (s.length !== t.length) return false
  const n = s.length
  const map = Array(26).fill(0)
  const base = 'a'.charCodeAt(0)
  for (let i = 0; i < n; i++) {
    map[s[i].charCodeAt(0) - base]++
    map[t[i].charCodeAt(0) - base]--
  }
  return map.every((v) => !v)
}
