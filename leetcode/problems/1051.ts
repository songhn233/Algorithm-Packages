function heightChecker(heights: number[]): number {
  const target = heights.slice()
  target.sort((a, b) => a - b)
  return heights.reduce((ans, v, i) => (v !== target[i] ? ans + 1 : ans), 0)
}
