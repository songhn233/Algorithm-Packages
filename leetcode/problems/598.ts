function maxCount(m: number, n: number, ops: number[][]): number {
  let x = m,
    y = n
  for (let [a, b] of ops) {
    x = Math.min(x, a)
    y = Math.min(y, b)
  }
  return x * y
}
