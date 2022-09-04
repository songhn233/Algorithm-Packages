function findLongestChain(pairs: number[][]): number {
  pairs.sort((a, b) => a[0] - b[0])
  const f = Array(pairs.length).fill(1),
    n = pairs.length
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < i; j++) {
      if (pairs[i][0] > pairs[j][1]) {
        f[i] = Math.max(f[i], f[j] + 1)
      }
    }
  }
  return Math.max(...f)
}
