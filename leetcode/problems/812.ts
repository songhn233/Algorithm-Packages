const largestTriangleArea = function (p: number[][]) {
  let ans = 0
  for (let i = 0; i < p.length; i++) {
    for (let j = i + 1; j < p.length; j++) {
      for (let k = j + 1; k < p.length; k++) {
        ans = Math.max(
          ans,
          Math.abs(
            (p[i][0] * (p[j][1] - p[k][1]) +
              p[j][0] * (p[k][1] - p[i][1]) +
              p[k][0] * (p[i][1] - p[j][1])) /
              2.0
          )
        )
      }
    }
  }
  return ans
}
