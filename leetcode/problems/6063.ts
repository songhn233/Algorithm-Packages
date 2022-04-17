function maximumScore(scores: number[], edges: number[][]): number {
  const map: Record<number, number[][]> = {},
    n = scores.length
  let ans = -1
  for (let i = 0; i < n; i++) {
    map[i] = []
  }
  edges.forEach(([x, y]) => {
    map[x].push([y, scores[y]])
    map[y].push([x, scores[x]])
  })
  for (let i = 0; i < n; i++) {
    map[i].sort((x, y) => y[1] - x[1])
    map[i] = map[i].slice(0, 3)
  }
  edges.forEach(([x, y]) => {
    const xx = map[x],
      yy = map[y]
    for (let i = 0; i < xx.length; i++) {
      for (let j = 0; j < yy.length; j++) {
        const a = xx[i][0],
          b = yy[j][0]
        if (a !== b && a !== y && b !== x) {
          ans = Math.max(ans, xx[i][1] + yy[j][1] + scores[x] + scores[y])
        }
      }
    }
  })
  return ans
}
