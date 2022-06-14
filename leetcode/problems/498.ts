function findDiagonalOrder(mat: number[][]): number[] {
  const ans: number[] = [],
    n = mat.length,
    m = mat[0].length
  let i = 0,
    j = 0,
    flag = 1
  const check = (x: number, y: number) => x >= 0 && x < n && y >= 0 && y < m
  while (ans.length !== n * m) {
    ans.push(mat[i][j])
    let ni = i,
      nj = j
    if (flag === 1) {
      --ni, ++nj
    } else {
      ++ni, --nj
    }
    if (!check(ni, nj)) {
      ;(ni = i), (nj = j)
      if (flag === 1) {
        if (j + 1 < m) nj = j + 1
        else ni = i + 1
      } else {
        if (i + 1 < n) ni = i + 1
        else nj = j + 1
      }
      flag = -flag
    }
    ;(i = ni), (j = nj)
  }
  return ans
}
