function findRepeatedDnaSequences(s: string): string[] {
  const map = new Map()
  let ans: string[] = []
  const n = s.length
  for (let i = 0; i <= n - 10; i++) {
    const str = s.slice(i, i + 10)
    map.set(str, (map.get(str) ?? 0) + 1)
    if (map.get(str) === 2) ans.push(str)
  }
  return ans
}
