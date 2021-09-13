function numberOfBoomerangs(points: number[][]): number {
  const map = new Map()
  const calc = (i: number, j: number) => {
    return (
      (points[i][0] - points[j][0]) * (points[i][0] - points[j][0]) +
      (points[i][1] - points[j][1]) * (points[i][1] - points[j][1])
    )
  }
  let ans = 0
  for (let i = 0; i < points.length; i++) {
    map.clear()
    for (let j = 0; j < points.length; j++) {
      if (j === i) continue
      const dis = calc(i, j)
      if (map.has(dis)) {
        map.set(dis, map.get(dis) + 1)
      } else {
        map.set(dis, 1)
      }
    }
    map.forEach((v) => (ans += v * (v - 1)))
  }
  return ans
}
