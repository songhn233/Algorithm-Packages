const canConstruct = (ransomNote: string, magazine: string) => {
  const calcMap = (s: string) =>
    s.split('').reduce((map, v) => {
      ++map[v.charCodeAt(0) - 'a'.charCodeAt(0)]
      return map
    }, Array(26).fill(0))
  const m1 = calcMap(ransomNote),
    m2 = calcMap(magazine)
  return m2.every((v, idx) => v >= m1[idx])
}
