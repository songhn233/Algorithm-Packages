function findAnagrams(s: string, p: string): number[] {
  const m1 = Array(26).fill(0),
    m2 = Array(26).fill(0)
  p.split('').forEach((c) => m1[c.charCodeAt(0) - 'a'.charCodeAt(0)]++)
  const squal = (a: number[], b: number[]) =>
    a.reduce((acc, v, idx) => (v === b[idx] ? acc : false), true)
  let ans: number[] = []
  s.split('').forEach((v, idx) => {
    m2[v.charCodeAt(0) - 'a'.charCodeAt(0)]++
    if (idx >= p.length - 1) {
      if (squal(m1, m2)) {
        ans.push(idx - p.length + 1)
      }
      m2[s[idx - p.length + 1].charCodeAt(0) - 'a'.charCodeAt(0)]--
    }
  })
  return ans
}
